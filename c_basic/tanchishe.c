// 作者：dm2
// 链接：https://www.zhihu.com/question/360814879/answer/1005146158
// 来源：知乎
// 著作权归作者所有。商业转载请联系作者获得授权，非商业转载请注明出处。

#include <Windows.h>
#include <stdio.h>
#include <conio.h>
#include <time.h>
#define PANIC(err) (fprintf(stderr,"PANIC Line %d : %s",__LINE__,err),exit(-1),1)
#define PANICIFNULL(EXP) ((EXP)==NULL && PANIC("NULL"))
typedef enum { EMPTY=0, WALL, BODY, FOOD } MAP;
typedef int POSITION;
struct { int color; const char* shape; } UI[] = {
	{2,"■"},{4,"□"},{6,"★"},{4,"●"}
};
struct {
	int WIDTH, HEIGHT, direction, delay;
	MAP* map;
	POSITION* body, head, tail, len;
} C;
void initConsole(int width, int height) {
	char cmd[100];
	sprintf_s(cmd,100, "mode con cols=%d lines=%d && title C语言贪吃蛇 By dreamer2q %s", width, height,__DATE__);
	system(cmd);
	HANDLE handle = GetStdHandle(STD_OUTPUT_HANDLE);
	CONSOLE_CURSOR_INFO cur_info;
	GetConsoleCursorInfo(handle, &cur_info);
	cur_info.bVisible = FALSE;
	SetConsoleCursorInfo(handle, &cur_info);
}
void updatePosition(POSITION pos) {
	HANDLE handle = GetStdHandle(STD_OUTPUT_HANDLE);
	COORD coord = { (pos % (C.WIDTH)) * 2 ,pos / (C.WIDTH) };
	SetConsoleCursorPosition(handle, coord);
	SetConsoleTextAttribute(handle, UI[C.map[pos]].color);
	printf("%s", UI[C.map[pos]].shape);
}
MAP food(int t) {
	POSITION pos = (rand() % ((C.WIDTH - 2) * (C.HEIGHT - 2))) + C.WIDTH + 1;
	if (C.map[pos]) return food(t);
	else return  (C.map[pos] = FOOD) ? updatePosition(pos), BODY : BODY;
}
int init() {
	C.WIDTH = C.HEIGHT = 30;
	initConsole(C.WIDTH * 2, C.HEIGHT);
	PANICIFNULL(C.map = (MAP*)malloc((C.WIDTH) * (C.HEIGHT) * sizeof(MAP)));
	PANICIFNULL(C.body = (POSITION*)malloc(C.WIDTH * C.HEIGHT * sizeof(POSITION)));
	C.head = (C.len = 3) - 1;
	C.direction = (C.tail = 0) + 1;
	C.delay = -150;
	memset(C.map, EMPTY, (C.WIDTH) * (C.HEIGHT) * sizeof(MAP));
	for (int i = 0; i < (C.WIDTH) * (C.HEIGHT); i++) {
		i < C.WIDTH && (C.map[i] = C.map[C.WIDTH * (C.HEIGHT - 1) + i] = WALL);
		i < C.HEIGHT && (C.map[C.WIDTH * i] = C.map[C.WIDTH * i + C.WIDTH - 1] = WALL);
		i < C.len && (C.map[C.body[i] = C.WIDTH * C.HEIGHT / 2 + C.WIDTH / 2 - 1 + i] = BODY);
		updatePosition(i);
	}
	srand(time(NULL));
	return food(0);
}
int Run(int shit) {
	int prv = 77;
	while (1) {
		if (_kbhit()) {
			int t = _getch();
			if ((prv + t) == 152)continue;
			switch (t) {
			case 72:C.direction = -C.WIDTH; break;
			case 80:C.direction = C.WIDTH; break;
			case 75:C.direction = -1; break;
			case 77:C.direction = 1; break;
			case ' ':C.delay = -C.delay; break;
			default:continue;
			}
			prv = t;
		}
#define INC(p) (((p)+1)%(C.WIDTH*C.HEIGHT))
		if (C.delay > 0) Sleep(C.delay);
		else continue;
		switch (C.map[C.body[INC(C.head)] = C.body[C.head] + C.direction]) {
		case FOOD:food(C.len = -C.len - 1);
		case EMPTY:
			C.map[C.body[C.head = INC(C.head)]] = BODY;
			updatePosition(C.body[C.head]);
			if (C.len > 0) updatePosition((C.map[C.body[C.tail]] = EMPTY) ? BODY : C.body[C.tail]), C.tail = INC(C.tail);
			else C.len = -C.len;
			break;
		case WALL:case BODY:
			return -1;//dead
		}
	}
}
int main() {
	while (1) {
		initConsole(25, 10);
		printf("\n\tC语言贪吃蛇\n\n    1. 开始游戏\n    2. 关于\n    q. 退出\n%");
		switch (_getch()) {
		case 'q':return 0;
		case '2':MessageBoxA(GetConsoleWindow(), "100行代码？", "有病吧你？", MB_OK|MB_ICONASTERISK); continue;
		case '1':Run(init());
			MessageBoxA(GetConsoleWindow(), "你死了。有病去看看吧", "SHIT", MB_OK | MB_ICONERROR);
		}
	}
}