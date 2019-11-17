#pragma once
class WindowsApplication
{
public:
	~WindowsApplication();

	static WindowsApplication& Inst();

	bool Initialize(HINSTANCE hInInstance, int nCmdShow);
	int GoMsgLoop();

protected:
	static LRESULT CALLBACK AppWndProc(HWND hwnd, unsigned int msg, WPARAM wParam, LPARAM lParam);
	static INT_PTR CALLBACK About(HWND hDlg, UINT message, WPARAM wParam, LPARAM lParam);

	LRESULT ProcessMessage(HWND hwnd, unsigned int msg, WPARAM wParam, LPARAM lParam);

private:
	void RegistClass();
	WindowsApplication();

	HINSTANCE hInst;

	static constexpr int MAX_LOADSTRING = 100;
	WCHAR szTitle[MAX_LOADSTRING]{ L"MyAppTitle" };	// ���� ǥ���� �ؽ�Ʈ�Դϴ�.
	WCHAR szWindowClass[MAX_LOADSTRING]{ L"MyApp" };	// �⺻ â Ŭ���� �̸��Դϴ�.
	HACCEL hAccelTable;
};

