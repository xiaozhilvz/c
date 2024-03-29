#include <iostream>
#include <opencv2/opencv.hpp>
#include <Windows.h>

// ģ�����������
void simulateMouseClick(int x, int y) {
    INPUT input = { 0 };
    input.type = INPUT_MOUSE;
    input.mi.dwFlags = MOUSEEVENTF_ABSOLUTE | MOUSEEVENTF_MOVE | MOUSEEVENTF_LEFTDOWN;
    input.mi.dx = x * (65535 / GetSystemMetrics(SM_CXSCREEN));
    input.mi.dy = y * (65535 / GetSystemMetrics(SM_CYSCREEN));
    SendInput(1, &input, sizeof(INPUT));

    // �ȴ�һС��ʱ�䣬ģ����갴��
    Sleep(50);

    // ��������ͷ��¼�
    input.mi.dwFlags = MOUSEEVENTF_ABSOLUTE | MOUSEEVENTF_MOVE | MOUSEEVENTF_LEFTUP;
    SendInput(1, &input, sizeof(INPUT));
}

int main() {
    // ��ȡ�ض�ͼƬ
    cv::Mat specific_image = cv::imread("D:\\c\\NB.png");

    while (true) {
        // ��ȡ��Ļͼ��
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

        // ����Ļͼ��ת��ΪOpenCV��ʽ
        cv::Mat screen_image(GetSystemMetrics(SM_CYSCREEN), GetSystemMetrics(SM_CXSCREEN), CV_8UC4);
        GetDIBits(hDC, hBitmap, 0, GetSystemMetrics(SM_CYSCREEN), screen_image.data, (BITMAPINFO*)&bi, DIB_RGB_COLORS);

        // ����Ļͼ����Ѱ���ض�ͼƬ
        cv::Mat result;
        cv::matchTemplate(screen_image, specific_image, result, cv::TM_CCOEFF_NORMED);
        cv::threshold(result, result, 0.8, 1.0, cv::THRESH_TOZERO);

        double minval, maxval;
        cv::Point minloc, maxloc;
        cv::minMaxLoc(result, &minval, &maxval, &minloc, &maxloc);

        // �����⵽�ض�ͼƬ����ģ�������
        if (maxval > 0.8) {
            int x = maxloc.x + specific_image.cols / 2;  // ���λ�õ�x����
            int y = maxloc.y + specific_image.rows / 2;  // ���λ�õ�y����
            simulateMouseClick(x, y);

            // ģ������ȴ�һ��ʱ�䣬�����ظ����
            Sleep(1000);
        }

        // �ͷ���Դ
        SelectObject(hDC, old_obj);
        DeleteDC(hDC);
        ReleaseDC(NULL, hScreen);
        DeleteObject(hBitmap);
    }

    return 0;
}