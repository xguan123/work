#include <opencv2/opencv.hpp>
#include <iostream>
#include <vector>
#include <string>

void processFrame(const cv::Mat& frame, cv::Mat& result,int recorange,int recocolor,int blurdistance) {
    result = frame.clone();
    cv::Mat cyan_mask;
    
    cv::inRange(frame, 
               cv::Scalar(recocolor, recocolor, 0),    
               cv::Scalar(255, 255, 250), 
               cyan_mask);

    cv::Mat kernel = cv::getStructuringElement(cv::MORPH_ELLIPSE, cv::Size(3, 3));
    cv::morphologyEx(cyan_mask, cyan_mask, cv::MORPH_CLOSE, kernel); 
    cv::morphologyEx(cyan_mask, cyan_mask, cv::MORPH_OPEN, kernel);   

    std::vector<std::vector<cv::Point>> contours;
    std::vector<cv::Vec4i> hierarchy;
    cv::findContours(cyan_mask, contours, hierarchy, 
                    cv::RETR_EXTERNAL, cv::CHAIN_APPROX_SIMPLE);

    for (size_t i = 0; i < contours.size(); ++i) {
        double area = cv::contourArea(contours[i]);
        if (area < recorange)  // 过滤小面积
            continue;

        double perimeter = cv::arcLength(contours[i], true);

        // 多边形逼近
        std::vector<cv::Point> corners;
        double epsilon = 0.03 * perimeter;  
        cv::approxPolyDP(contours[i], corners, epsilon, true);
        // 合并过近的点
        int k0 = -1;
        std::vector<cv::Point> processedCorners;
        for (size_t j = 0; j < corners.size(); ++j) {
            if (j > 0 && 
                std::abs(corners[j].x - corners[j - 1].x) <= blurdistance && 
                std::abs(corners[j].y - corners[j - 1].y) <= blurdistance ) {
                cv::Point avgPoint((corners[j].x + corners[j - 1].x) / 2, 
                                  (corners[j].y + corners[j - 1].y) / 2);
                processedCorners.pop_back();
                processedCorners.push_back(avgPoint);
            } else {
                k0++;
                processedCorners.push_back(corners[j]);
            }
        }
        // 检查首尾
        if(processedCorners.size() > 1 &&
           std::abs(processedCorners[k0].x - processedCorners[0].x) <= blurdistance && 
           std::abs(processedCorners[k0].y - processedCorners[0].y) <= blurdistance){
           processedCorners[0].x = (processedCorners[0].x + processedCorners[k0].x) / 2;
           processedCorners[0].y = (processedCorners[0].y + processedCorners[k0].y) / 2;
           processedCorners.pop_back();
        }
        // 绘制角点
        for (const auto& corner : processedCorners) {
            cv::circle(result, corner, 3, cv::Scalar(0, 0, 255), -1);
        }
    }
}

int main() {
    std::string imagePath = "origin_pic.jpg";
    std::string videoPath = "test_hik_1.avi";
    std::string outputVideoPath = "result.avi"; 
    
    cv::namedWindow("origin", cv::WINDOW_NORMAL);
    cv::namedWindow("outcome", cv::WINDOW_NORMAL);
    
    std::cout << "Input the type：" << std::endl;
    std::cout << "1 picture (" << imagePath << ")  " << "2 vedio (" << videoPath << ")" << std::endl;
    
    int choice;
    std::cin >> choice;

    if (choice == 1) {
        cv::Mat ori = cv::imread(imagePath);

        cv::Mat result;
        processFrame(ori, result, 80, 250, 30);

        cv::imshow("origin", ori);
        cv::imshow("outcome", result);
        cv::waitKey(0);  
    } 
    else if (choice == 2) {
        cv::VideoCapture cap(videoPath);
        if (!cap.isOpened()) {
            std::cerr << "can't find video " << videoPath << std::endl;
            return -1;
        }

        int frameWidth = cap.get(cv::CAP_PROP_FRAME_WIDTH);
        int frameHeight = cap.get(cv::CAP_PROP_FRAME_HEIGHT);
        double fps = cap.get(cv::CAP_PROP_FPS);
        cv::VideoWriter writer(outputVideoPath, cv::VideoWriter::fourcc('M','J','P','G'), fps, cv::Size(frameWidth, frameHeight));

        cv::Mat frame, result;
        while (true) {
            cap >> frame;
            if (frame.empty()) break; 

            processFrame(frame, result, 30, 210, 20);

            cv::imshow("origin", frame);
            cv::imshow("outcome", result);
            writer.write(result);
            cv::waitKey(25);
        }
        writer.release();
        cap.release();
    } 
    else {
        std::cerr << "invaild input" << std::endl;
        return -1;
    }

    cv::destroyAllWindows();
    return 0;
}
