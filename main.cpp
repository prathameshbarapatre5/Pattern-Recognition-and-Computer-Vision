#include <opencv2/opencv.hpp>
#include <iostream>

int main() {
    std::cout << "OpenCV Version: " << CV_VERSION << std::endl;
    std::cout << "Installation Successful!" << std::endl;
    
    // Create a simple blank image
    cv::Mat image = cv::Mat::zeros(300, 300, CV_8UC3);
    cv::putText(image, "OpenCV Works!", cv::Point(50, 150), 
                cv::FONT_HERSHEY_SIMPLEX, 1.0, cv::Scalar(0, 255, 0), 2);

    std::cout << "Created a sample image matrix." << std::endl;
    // cv::imshow("Test", image); // GUI might not be available or block
    // cv::waitKey(0);
    
    return 0;
}
