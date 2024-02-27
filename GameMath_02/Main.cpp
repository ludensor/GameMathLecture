#include <Windows.h>

#include "MathUtils.h"

/**
 * 이번 예제에서는 사각형 도형을 Vector2를 사용하여 위, 아래, 좌, 우 방향으로 움직이는 코드를 작성해 봅니다.
 */

 // 윈도우 창 사이즈
constexpr int WIN_WIDTH = 1600;
constexpr int WIN_HEIGHT = 900;

// 박스의 속도
constexpr float MOVE_SPEED = 800.0f;

// TODO: 임의의 방향을 설정하고 크기가 MOVE_SPEED인 방향벡터를 만드는 식을 작성하시오
Vector2 velocity = // ?

// 박스의 위치 좌표
Vector2 position{ 400.0f, 400.0f };

// 박스의 크기
Vector2 size{ 40.0f, 40.0f };

constexpr int WALL_COUNT = 4;

// 벽
Box walls[WALL_COUNT]
{
	Box{ Vector2(0.0f, 0.0f), Vector2((float)WIN_WIDTH, 20.0f), Vector2::down },
	Box{ Vector2((float)WIN_WIDTH - 20.0f, 0.0f), Vector2((float)WIN_WIDTH, (float)WIN_HEIGHT), Vector2::left },
	Box{ Vector2(0.0f, (float)WIN_HEIGHT - 20.0f), Vector2((float)WIN_WIDTH, (float)WIN_HEIGHT), Vector2::up },
	Box{ Vector2(0.0f, 0.0f), Vector2(20.0f, (float)WIN_HEIGHT), Vector2::right }
};

LRESULT CALLBACK WndProc(HWND hWnd, UINT message, WPARAM wParam, LPARAM lParam);

void Update(float delta_time);
void Render(HDC hdc);
void DrawBox(HDC hdc, const Vector2& min, const Vector2& max, COLORREF color);

int WINAPI wWinMain(_In_ HINSTANCE hInstance, _In_opt_ HINSTANCE hPrevInstance, _In_ LPWSTR lpCmdLine, _In_ int nShowCmd)
{
	WNDCLASSEX wc{ sizeof(WNDCLASSEX), CS_HREDRAW | CS_VREDRAW, WndProc, 0, 0, hInstance, nullptr, LoadCursor(nullptr, IDC_ARROW), (HBRUSH)(COLOR_WINDOW + 1), nullptr, TEXT("GameMath"), nullptr };
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
	position += velocity * delta_time;

	for (int i = 0; i < WALL_COUNT; ++i)
	{
		RECT rc;
		RECT src1{ (LONG)(position.x - size.x * 0.5f), (LONG)(position.y - size.y * 0.5f),  (LONG)(position.x + size.x * 0.5f), (LONG)(position.y + size.y * 0.5f) };
		RECT src2{ (LONG)walls[i].min.x, (LONG)walls[i].min.y, (LONG)walls[i].max.x, (LONG)walls[i].max.y };
		const bool is_collision = IntersectRect(&rc, &src1, &src2);

		if (is_collision)
		{
			// TODO: 박스가 벽에 충돌했을 때 반사하도록 코드를 작성하시오
		}
	}
}

void Render(HDC hdc)
{
	DrawBox(hdc, Vector2{ position.x - size.x * 0.5f, position.y - size.y * 0.5f }, Vector2{ position.x + size.x * 0.5f, position.y + size.y * 0.5f }, RGB(0, 255, 255));

	for (int i = 0; i < WALL_COUNT; ++i)
	{
		DrawBox(hdc, walls[i].min, walls[i].max, RGB(0, 255, 0));
	}
}

void DrawBox(HDC hdc, const Vector2& min, const Vector2& max, COLORREF color)
{
	// 박스 칠하기
	HPEN pen = (HPEN)CreatePen(PS_SOLID, 1, color);
	HPEN old_pen = (HPEN)SelectObject(hdc, pen);
	Rectangle(hdc, (int)min.x, (int)min.y, (int)max.x, (int)max.y);
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

