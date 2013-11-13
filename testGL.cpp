// testGL.cpp : コンソール アプリケーションのエントリ ポイントを定義します。
//
#include "stdafx.h"
#include "GL/glut.h"
#include <iostream>
#include <ctype.h>
#define _USE_MATH_DEFINES 1
#include <math.h>
#define WINDOW_X ((GetSystemMetrics( SM_CXSCREEN ) - width ) / 2)  // ウィンドウの表示位置
#define WINDOW_Y ((GetSystemMetrics( SM_CYSCREEN ) - height ) / 2) // ウィンドウの表示位置
#define WORLD_Y 10
#define WORLD_Z 4
#define WORLD_X 30
//glutSetCursor(GLUT_CURSOR_NONE);
//y,z,x

int width=640,height=480;
int world[WORLD_Y][WORLD_Z][WORLD_X] = 
{
	{{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0}},
	{{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0}},
	{{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0}},
	{{0,1,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,1,1,0,1,0,0,0,0,0},{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0}},
	{{1,0,0,1,0,0,0,0,0,0,0,1,1,0,0,0,1,1,0,1,0,0,0,0,1,0,0,0,0,0},{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0}},
	{{1,0,0,1,0,1,1,1,0,0,1,0,0,1,0,1,0,1,0,1,0,1,1,0,1,0,0,0,0,0},{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0}},
	{{1,0,0,1,0,1,0,0,1,0,1,1,1,1,0,1,0,1,0,1,0,0,1,0,1,0,0,0,0,0},{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0}},
	{{0,1,1,0,0,1,1,1,0,0,1,0,0,0,0,1,0,1,0,0,1,1,1,0,1,1,1,1,0,0},{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0}},
	{{0,0,0,0,0,1,0,0,0,0,0,1,1,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0}},
	{{1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1},{1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1},{1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1},{1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1}},
};
double rad(int deg)
{
	return deg * M_PI / 180.0;
}
static double objX,objY,objZ;
void scene(void)
{/*
	glDisable(GL_DEPTH_TEST);
	glCullFace(GL_BACK);
        glEnable(GL_CULL_FACE); *//*
	 glEnable(GL_POLYGON_SMOOTH);
 glEnable(GL_BLEND);
 glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
 glHint(GL_POLYGON_SMOOTH_HINT, GL_DONT_CARE);*/
	/* 物体の色 */
	static GLfloat red[] = { 0.8, 0.2, 0.2, 1.0 };
	static GLfloat green[] = { 0.2, 0.8, 0.2, 1.0 };
	static GLfloat blue[] = { 0.2, 0.2, 0.8, 1.0 };
	static GLfloat yellow[] = { 0.8, 0.8, 0.2, 1.0 };
	static GLfloat ground[][4] = {
		{ 0.6, 0.6, 0.6, 1.0 },
		{ 0.3, 0.3, 0.3, 1.0 }
	};
	int i, j;
	static double siz=1.0;
	static double siz2=1.0/siz;
	/* 赤い箱 */
	//for(int y=WORLD_Y-1;y>=0;y--)
	BOOL flg=FALSE;
	for(int y=0;y<WORLD_Y;y++)
	{
		for(int z=0;z<WORLD_Z;z++)
		{
			for(int x=0;x<WORLD_X;x++)
			{
				if(world[y][z][x]==1)
				{
					glPushMatrix();

					double sx=(double)x/siz,sy=(WORLD_Y-1-y)/siz,sz=(double)z/siz;
					glTranslated(sx,/*0 (double)*/sy, sz);
					if(sx>=objX-siz2&&//sx+siz2<=objX+siz2&&
						sy>=objY-siz2&&//sy+siz2<=objY-siz2&&
						sz>=objZ-siz2&&!flg)//&&sz+siz2<=objZ+siz2)
					{
						glMaterialfv(GL_FRONT, GL_DIFFUSE, yellow);
						//flg=TRUE;
					}
					else
						glMaterialfv(GL_FRONT, GL_DIFFUSE, green);


					glutSolidCube(1.0/siz);
					glPopMatrix();
				}
			}
		}
	}
	/* 緑の箱 
	glPushMatrix();
	glTranslated(0.0, 0.0, 3.0);
	glMaterialfv(GL_FRONT, GL_DIFFUSE, green);
	glutSolidCube(1.0);
	glPopMatrix();

	/* 青い箱 
	glPushMatrix();
	glTranslated(-3.0, 0.0, 0.0);
	glMaterialfv(GL_FRONT, GL_DIFFUSE, blue);
	glutSolidCube(1.0);
	glPopMatrix();

	/* 黄色い箱 
	glPushMatrix();
	glTranslated(3.0, 0.0, 0.0);
	glMaterialfv(GL_FRONT, GL_DIFFUSE, yellow);
	glutSolidCube(1.0);
	glPopMatrix();


	/* 地面 *//*
	glPushMatrix();
	//glTranslated((int)(objX*0.25)/0.25, (int)(objY*0.25)/0.25, (int)(objZ*0.25)/0.25);
	glTranslated(objX,objY,objZ);
	glMaterialfv(GL_FRONT, GL_DIFFUSE, yellow);
	glutSolidCube(1.0/siz);
	glPopMatrix();*/

	glBegin(GL_QUADS);
	glNormal3d(0.0, 1.0, 0.0);
	for (j = -5; j < WORLD_Z; ++j) {
		for (i = -5; i < WORLD_X; ++i) {
			glMaterialfv(GL_FRONT, GL_DIFFUSE, ground[(i + j) & 1]);
			glVertex3d((GLdouble)i, -0.5, (GLdouble)j);
			glVertex3d((GLdouble)i, -0.5, (GLdouble)(j + 1));
			glVertex3d((GLdouble)(i + 1), -0.5, (GLdouble)(j + 1));
			glVertex3d((GLdouble)(i + 1), -0.5, (GLdouble)j);
		}
	}
	HDC glDc = wglGetCurrentDC();
	//HWND hWnd = WindowFromDC(glDc);
	POINT t = {width/2-8,height/2-8};
	LPPOINT lp = (LPPOINT)&t;
	MoveToEx(glDc,width/2-8,height/2,lp);
	LineTo( glDc, width/2+8,height/2 );

	glEnd();
}
double displayex=0.0+0.0;
double displayez=0.0+0.0;
double displayrx=0.0+0.0;
double displayry=0.0+0.0;
double size=1.0;//2.5;
void display(void)
{
	static GLfloat lightpos[] = { 3.0, 4.0, 5.0, 1.0 }; /* 光源の位置 */

	static double ex = 0.0, ez = 0.0; /* 視点の位置 */
	static double r = 0.0+9.0;            /* 視点の向き */
	static double s = 2.5;
	/* 画面クリア */
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

	/* モデルビュー変換行列の初期化 */
	glLoadIdentity();

	/* 視点の移動 */
	//glRotated(r, 0.0, 1.0, 0.0);

	glRotated(displayry, 0.00001, 0.0, 0.0);
	glRotated(displayrx, 0.0, 1.0, 0.0);
	glTranslated(displayex, 0.0, displayez);
	glScaled(size,size,size);
	//printf("hoge");
	/* 光源の位置を設定 */
	glLightfv(GL_LIGHT0, GL_POSITION, lightpos);

	/* シーンの描画 */
	scene();

	glFlush();
}
void resize(int w, int h)
{
	width=w;height=h;
	/* ウィンドウ全体をビューポートにする */
	glViewport(0, 0, w, h);

	/* 透視変換行列の指定 */
	glMatrixMode(GL_PROJECTION);

	/* 透視変換行列の初期化 */
	glLoadIdentity();
	gluPerspective(30.0, (double)w / (double)h, 1.0, 100.0);

	/* モデルビュー変換行列の指定 */
	glMatrixMode(GL_MODELVIEW);
}

void keyboard(unsigned char key, int x, int y)
{
	/* ESC か q をタイプしたら終了 */
	if (key == '\033' || key == 'q') {
		exit(0);
	}
	switch (key)
	{
	case'w':
		displayez+=cos(rad(displayrx))/10;
		displayex-=sin(rad(displayrx))/10;
		display();
		break;
	case's':
		displayez-=cos(rad(displayrx))/10;
		displayex+=sin(rad(displayrx))/10;
		display();
		//if(displayrx >= 90)displayez+=0.1;else displayez-=0.1;display();
		break;
	case'a':
		//displayex-=0.1;
		//displayez-=sin(rad(displayrx))/10;
		displayez+=cos(rad(displayrx-90))/10;
		displayex-=sin(rad(displayrx-90))/10;
		display();
		break;
	case'd':
		displayez-=cos(rad(displayrx-90))/10;
		displayex+=sin(rad(displayrx-90))/10;
		display();
		break;
	default:
		break;
	}
}
//int flag;
void idle(void)
{
	/*if(flag){size-=0.001f;}else{size+=0.001f;}
	if(size>3.0f)flag=true;
	if(size<1.0f)flag=false;*/
	glutPostRedisplay();
}
void init(void)
{
	/* 初期設定 */
	glClearColor(1.0, 1.0, 1.0, 0.0);
	glEnable(GL_DEPTH_TEST);
	glEnable(GL_CULL_FACE);
	glEnable(GL_LIGHTING);
	glEnable(GL_LIGHT0);

	glEnable(GL_BLEND);
glEnable(GL_CULL_FACE);//陰面消去しておくとより顕著にわかりやすく見えるのでEnableにした
glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);//back-to-front
glHint(GL_POLYGON_SMOOTH_HINT,GL_NICEST);
glEnable(GL_POLYGON_SMOOTH);    
}
int oldx=-1,oldy=-1;
void mouse(/*int button, int state, */int x, int y)
{
	//printf("x=%d,y=%d",x,y);
	//SetCursorPos(/*WINDOW_X+*/GetSystemMetrics( SM_CXSCREEN )+width/2,/*WINDOW_Y+*/GetSystemMetrics( SM_CYSCREEN )+height/2);
	//SetCursorPos(/*WINDOW_X+*/GetSystemMetrics( SM_CXSCREEN ),/*WINDOW_Y+*/GetSystemMetrics( SM_CYSCREEN ));
	//GLのデバイスコンテキストハンドル取得
	HDC glDc = wglGetCurrentDC();
	HWND hWnd = WindowFromDC(glDc)	;
	RECT lp;
	POINT po;
	GetCursorPos((LPPOINT)&po);
	GetWindowRect(hWnd,(LPRECT)&lp);
	//printf("x=%d,y=%d,r=%d",lp.left,lp.top,displayr);
	//printf("x=%d,y=%d,r=%d",po.x,po.y,displayr);
	int sx = lp.left + width / 2;
	int sy = lp.top + height / 2;
	if(oldx != -1 && oldy != -1)
	{
		int sax=0.5;
		int say=0.5;
		sax=(po.x-sx)/2;
		say=(po.y-sy)/2;
		if(po.x > sx)displayrx += sax;
		if(po.x < sx)displayrx += sax;
		if(po.y > sy)displayry += say;
		if(po.y < sy)displayry += say;
		if(displayry < -90.0)displayry = -90.0;
		if(displayry > 90.0)displayry = 90.0;

	}

	SetCursorPos(sx,sy);

	oldx = po.x;
	oldy = po.y;
	x-=4;y-=4;
	static double modelview[16]; //モデルビュー
	glGetDoublev(GL_MODELVIEW_MATRIX, modelview);
	static double projection[16]; //プロジェクション
	glGetDoublev(GL_PROJECTION_MATRIX, projection);
	static int viewport[4]; //ビューポート
	glGetIntegerv(GL_VIEWPORT, viewport);
	static float z;
	//ピクセルのデプス値を取得
	glReadPixels(x,glutGet(GLUT_WINDOW_HEIGHT) - y,1,1,GL_DEPTH_COMPONENT,GL_FLOAT,&z);
	//計算
	gluUnProject(x,glutGet(GLUT_WINDOW_HEIGHT) - y ,z,modelview,projection,viewport,&objX,&objY,&objZ);

	std::cout << "(x,y,z) = ("<<objX<<", "<<objY<<", "<<objZ<<")\n"; //出力
	//objX-=0.25;
	//objY-=0.25;
	//objZ-=0.25;

	glutPostRedisplay();
	display();
}

void mouseclick(int button, int state, int x, int y)
{

}
int main(int argc, char *argv[])
{
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_RGBA | GLUT_DEPTH);
	glutInitWindowSize(640,480);
	glutCreateWindow(argv[0]);

	glutSetWindowTitle("testGL");
	glutSetCursor(GLUT_CURSOR_NONE);
	glutDisplayFunc(display);
	glutReshapeFunc(resize);
	glutKeyboardFunc(keyboard);
	glutMouseFunc(mouseclick);
	glutPassiveMotionFunc(mouse);
	glutIdleFunc(idle);
	init();

	glutMainLoop();
	return 0;
}