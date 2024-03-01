#include <Windows.h>

#include "MathUtils.h"

/**
 * 이번 예제에서는 극좌표계에서 데카르트 좌표계로 변환하는 코드를 작성해 봅니다.
 */

 // 윈도우 창 사이즈
constexpr int WIN_WIDTH = 1600;
constexpr int WIN_HEIGHT = 900;

// 반지름 크기 확대, 축소 속도
constexpr float SCALE_RATE = 100.0f;

// 원의 반지름
float radius = 50.0f;

// 점의 개수
int num_points = 8;

LRESULT CALLBACK WndProc(HWND hWnd, UINT message, WPARAM wParam, LPARAM lParam);

void Update(float delta_time);
void Render(HDC hdc);
void DrawPoint(HDC hdc, const Vector2& position, COLORREF color);

int WINAPI wWinMain(_In_ HINSTANCE hInstance, _In_opt_ HINSTANCE hPrevInstance, _In_ LPWSTR lpCmdLine, _In_ int nShowCmd)
{
	WNDCLASSEX wc{ sizeof(WNDCLASSEX), CS_HREDRAW | CS_VREDRAW, WndProc, 0, 0, hInstance, nullptr, LoadCursor(nullptr, IDC_ARROW), (HBRUSH)(COLOR_WINDOW + 1), nullptr, TEXT("GAMEMATH"), nullptr };
	RegisterClassEx(&wc);

	RECT rc{ 0, 0, WIN_WIDTH, WIN_HEIGHT };
	AdjustWindowRect(&rc, WS_OVERLAPPEDWINDOW, false);

	HWND hWnd = CreateWindow(wc.lpszClassName, TEXT("GameMath"), WS_OVERLAPPEDWINDOW, CW_USEDEFAULT, CW_USEDEFAULT, rc.right - rc.left, rc.bottom - rc.top, nullptr, nullptr, hInstance, nullptr);

	ShowWindow(hWnd, nShowCmd);
	UpdateWindow(hWnd);

	LARGE_INTEGER prev_time, current_time;
	QueryPerformanceCounter(&prev_time);

	LARGE_INTEGER cpu_tick;
	QueryPerformanceFrequency(&cpu_tick);

	HDC screen_dc = GetDC(hWnd);
	HDC mem_dc = CreateCompatibleDC(screen_dc);
	HBITMAP mem_bitmap = CreateCompatibleBitmap(screen_dc, WIN_WIDTH, WIN_HEIGHT);
	HBITMAP old_bitmap = (HBITMAP)SelectObject(mem_dc, mem_bitmap);

	MSG msg{};
	while (msg.message != WM_QUIT)
	{
		if (PeekMessage(&msg, nullptr, 0, 0, PM_REMOVE))
		{
			TranslateMessage(&msg);
			DispatchMessage(&msg);
		}
		else
		{
			QueryPerformanceCounter(&current_time);
			const float delta_time = (current_time.QuadPart - prev_time.QuadPart) / (float)cpu_tick.QuadPart;
			prev_time = current_time;

			Update(delta_time);

			// 기본 브러쉬 투명하게 만들기
			SelectObject(mem_dc, GetStockObject(NULL_BRUSH));

			// 배경색 칠하기
			HBRUSH brush = (HBRUSH)CreateSolidBrush(RGB(50, 50, 50));
			HBRUSH olb_brush = (HBRUSH)SelectObject(mem_dc, brush);
			Rectangle(mem_dc, 0, 0, WIN_WIDTH, WIN_HEIGHT);
			brush = (HBRUSH)SelectObject(mem_dc, olb_brush);
			DeleteObject(brush);

			Render(mem_dc);

			// 화면 깜빡임 방지를 위해 더블 버퍼링을 사용한다
			BitBlt(screen_dc, 0, 0, WIN_WIDTH, WIN_HEIGHT, mem_dc, 0, 0, SRCCOPY);
		}
	}

	mem_bitmap = (HBITMAP)SelectObject(mem_dc, old_bitmap);
	DeleteObject(mem_bitmap);

	DeleteDC(mem_dc);
	ReleaseDC(hWnd, screen_dc);

	UnregisterClass(wc.lpszClassName, hInstance);

	return (int)msg.wParam;
}

void Update(float delta_time)
{
	if (GetAsyncKeyState('W') & 0x8000)
	{
		radius += SCALE_RATE * delta_time;
		radius = math::Min(radius, 300.0f);
	}
	else if (GetAsyncKeyState('S') & 0x8000)
	{
		radius -= SCALE_RATE * delta_time;
		radius = math::Max(radius, 30.0f);
	}

	static float elapsed_time;
	elapsed_time += delta_time;
	if (elapsed_time > 0.02f)
	{
		if (GetAsyncKeyState('E') & 0x8000)
		{
			num_points += 1;
			num_points = math::Min(num_points, 64);
		}
		else if (GetAsyncKeyState('Q') & 0x8000)
		{
			num_points -= 1;
			num_points = math::Max(num_points, 4);
		}

		elapsed_time = 0.0f;
	}
}

void Render(HDC hdc)
{
	constexpr Vector2 center{ (float)(WIN_WIDTH >> 1), (float)(WIN_HEIGHT >> 1) };

	// TODO: center 위치를 중심으로 점을 찍어 원을 그리는 코드를 작성하시오
}

void DrawPoint(HDC hdc, const Vector2& position, COLORREF color)
{
	// 원 그리기
	HPEN pen = (HPEN)CreatePen(PS_SOLID, 1, color);
	HPEN old_pen = (HPEN)SelectObject(hdc, pen);
	Ellipse(hdc, (int)(position.x - 10.0f), (int)(position.y - 10.0f), (int)(position.x + 10.0f), (int)(position.y + 10.0f));
	pen = (HPEN)SelectObject(hdc, old_pen);
	DeleteObject(pen);
}

LRESULT CALLBACK WndProc(HWND hWnd, UINT message, WPARAM wParam, LPARAM lParam)
{
	switch (message)
	{
	case WM_KEYDOWN:
		switch (wParam)
		{
		case VK_ESCAPE:
			PostMessage(hWnd, WM_DESTROY, 0, 0);
			break;
		}
		break;

	case WM_DESTROY:
		PostQuitMessage(0);
		return 0;
	}

	return DefWindowProc(hWnd, message, wParam, lParam);
}

