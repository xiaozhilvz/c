#include <iostream>
#include <opencv2/opencv.hpp>
#include <Windows.h>

// 模拟鼠标点击函数
void simulateMouseClick(int x, int y) {
    INPUT input = { 0 };
    input.type = INPUT_MOUSE;
    input.mi.dwFlags = MOUSEEVENTF_ABSOLUTE | MOUSEEVENTF_MOVE | MOUSEEVENTF_LEFTDOWN;
    input.mi.dx = x * (65535 / GetSystemMetrics(SM_CXSCREEN));
    input.mi.dy = y * (65535 / GetSystemMetrics(SM_CYSCREEN));
    SendInput(1, &input, sizeof(INPUT));

    // 等待一小段时间，模拟鼠标按下
    Sleep(50);

    // 发送鼠标释放事件
    input.mi.dwFlags = MOUSEEVENTF_ABSOLUTE | MOUSEEVENTF_MOVE | MOUSEEVENTF_LEFTUP;
    SendInput(1, &input, sizeof(INPUT));
}

int main() {
    // 读取特定图片
    cv::Mat specific_image = cv::imread("D:\\c\\NB.png");

    while (true) {
        // 截取屏幕图像
        HDC hScreen = GetDC(NULL);
        HDC hDC = CreateCompatibleDC(hScreen);
        HBITMAP hBitmap = CreateCompatibleBitmap(hScreen, GetSystemMetrics(SM_CXSCREEN), GetSystemMetrics(SM_CYSCREEN));
        HGDIOBJ old_obj = SelectObject(hDC, hBitmap);
        BitBlt(hDC, 0, 0, GetSystemMetrics(SM_CXSCREEN), GetSystemMetrics(SM_CYSCREEN), hScreen, 0, 0, SRCCOPY);
        BITMAPINFOHEADER bi;
        bi.biSize = sizeof(BITMAPINFOHEADER);
        bi.biWidth = GetSystemMetrics(SM_CXSCREEN);
        bi.biHeight = GetSystemMetrics(SM_CYSCREEN);
        bi.biPlanes = 1;
        bi.biBitCount = 32;
        bi.biCompression = BI_RGB;
        bi.biSizeImage = 0;
        bi.biXPelsPerMeter = 0;
        bi.biYPelsPerMeter = 0;
        bi.biClrUsed = 0;
        bi.biClrImportant = 0;

        // 将屏幕图像转换为OpenCV格式
        cv::Mat screen_image(GetSystemMetrics(SM_CYSCREEN), GetSystemMetrics(SM_CXSCREEN), CV_8UC4);
        GetDIBits(hDC, hBitmap, 0, GetSystemMetrics(SM_CYSCREEN), screen_image.data, (BITMAPINFO*)&bi, DIB_RGB_COLORS);

        // 在屏幕图像中寻找特定图片
        cv::Mat result;
        cv::matchTemplate(screen_image, specific_image, result, cv::TM_CCOEFF_NORMED);
        cv::threshold(result, result, 0.8, 1.0, cv::THRESH_TOZERO);

        double minval, maxval;
        cv::Point minloc, maxloc;
        cv::minMaxLoc(result, &minval, &maxval, &minloc, &maxloc);

        // 如果检测到特定图片，则模拟鼠标点击
        if (maxval > 0.8) {
            int x = maxloc.x + specific_image.cols / 2;  // 点击位置的x坐标
            int y = maxloc.y + specific_image.rows / 2;  // 点击位置的y坐标
            simulateMouseClick(x, y);

            // 模拟点击后等待一段时间，避免重复点击
            Sleep(1000);
        }

        // 释放资源
        SelectObject(hDC, old_obj);
        DeleteDC(hDC);
        ReleaseDC(NULL, hScreen);
        DeleteObject(hBitmap);
    }

    return 0;
}