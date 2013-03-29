#include<GL/glut.h>
#include<stdio.h>
#include<stdlib.h>
void *currentfont;
GLfloat x[25];
GLfloat y[20];
GLint i,j,k;
int w,h;
void setFont(void *font)
{
	currentfont=font;
}



void drawstring(float x,float y,float z,char *str)
{
	    char *c;
	glRasterPos3f(x,y,z);
 
	for(c=str;*c!='\0';c++)
	{	glColor3f(0.0,0.0,0.0);
		glutBitmapCharacter(currentfont,*c);
	}
}



void text(void)											// to draw the text in menu screen
{

	

	setFont(GLUT_BITMAP_HELVETICA_18);
	glColor3f(1.0,1.0,1.0);
	drawstring(95.0,455.0,1.0,"*  *  *  *  *  *  *  *  *  GSM CALL SETUP PROCEDURE  *  *  *  *  *  *  *  *  *");

	glColor3f(1.0,1.0,1.0);
	drawstring(210.0,405.0,1.0,"First Use");				

	glColor3f(1.0,1.0,1.0);
	drawstring(200.0,350.0,1.0," Initiate Local Call");

	glColor3f(1.0,1.0,1.0);
	drawstring(210.0,295.0,1.0,"Initaite STD call");

	glColor3f(1.0,1.0,1.0);
	drawstring(200.0,240.0,1.0,"Some String");

	glColor3f(1.0,1.0,1.0);
	drawstring(215.0,185.0,1.0,"Some String");
	
	glColor3f(1.0,1.0,1.0);
	drawstring(225.0,130.0,1.0,"  EXIT");
	glFlush();
}


void draw() // TO DRAW POLYGON FOR DISPLAY MENUS 
{

	glClear(GL_COLOR_BUFFER_BIT);
    glBegin(GL_POLYGON);   //First use
	glColor3f(0.7f,0.2f,0.2f);
    glVertex2i(305,425);
	glVertex2i(180,425);
	glVertex2i(180,395);
    glVertex2i(305,395);
	glEnd();
	glFlush();

	glBegin(GL_POLYGON);  // Local Call
	glColor3f(0.7f,0.2f,0.2f);
    glVertex2i(305,370);
	glVertex2i(180,370);
	glVertex2i(180,340);
    glVertex2i(305,340);
	glEnd();
	glFlush();

	glBegin(GL_POLYGON);  // STD CAll 
	glColor3f(0.7f,0.2f,0.2f);
    glVertex2i(305,315);
	glVertex2i(180,315);
	glVertex2i(180,285);
    glVertex2i(305,285);
	glEnd();
	glFlush();

	glBegin(GL_POLYGON);  // Func 1
	glColor3f(0.7f,0.2f,0.2f);
    glVertex2i(305,260);
	glVertex2i(180,260);
	glVertex2i(180,230);
    glVertex2i(305,230);
	glEnd();
	glFlush();

	glBegin(GL_POLYGON);  // Func 2
	glColor3f(0.7f,0.2f,0.2f);
    glVertex2i(305,205);
	glVertex2i(180,205);
	glVertex2i(180,175);
    glVertex2i(305,175);
	glEnd();
	glFlush();

	glBegin(GL_POLYGON);  // exit
	glColor3f(0.7f,0.2f,0.2f);
    glVertex2i(305,150);
	glVertex2i(180,150);
	glVertex2i(180,120);
    glVertex2i(305,120);
	glEnd();
	glFlush();

}
		

void myInit()
{
    glClearColor(0.0,0.0,0.0,0.0);
	glColor3f(0.0f,0.0f,0.0f);
	glPointSize(5.0);
	gluOrtho2D(0.0,500.0,0.0,500.0);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	setFont(GLUT_BITMAP_HELVETICA_18);
	
}

void mobile_stn()		// to draw the sender and receiver MS
{


	glColor3f(1.0f,1.0f,1.0f);
	setFont(GLUT_BITMAP_HELVETICA_12);
 	drawstring(95.0,420.0,1.0,"SENDER");

	glColor3f(1.0f,1.0f,1.0f);
 	drawstring(345.0,420.0,1.0,"RECEIVER");
	
	/*Sender MS code*/
	/*Reciever MS code*/
        //BSS code
	//VLR code
	//HLR code
	//any other code for drawing 

	

	
}
   
void delay()
{
  j=20000;
	while(j!=0)
	{
		j--;
		i=20000;
		while(i!=0)
		{
			i--;
			
		}
	}


}






void timer(float k,float l,float m,float n)
{
glColor3f(1.4,1.9,0.78);
    glBegin(GL_POLYGON);         // to call timer functions
		glVertex2f(l,m);
	    glVertex2f(l,n);
		glVertex2f(l+k,m);
    glEnd();
	glFlush();

}



void title()												// to draw the starting screen
{
		glClear(GL_COLOR_BUFFER_BIT);
	setFont(GLUT_BITMAP_HELVETICA_18);


	glColor3f(1.0,1.0,1.0);
	drawstring(20.0,435.0,1.0,"*  * G R A P H I C A L   I L L U S T R A T I O N   OF   GSM CALL SETUP *  *");
	
	glColor3f(1.0,1.0,1.0);
	drawstring(210.0,365.0,1.0,"SUBMITTED   BY");				
	
	glColor3f(0.0,1.0,1.0);
	drawstring(180.0,340.0,1.0," Nitesh A Jain      1BY10CS047");
	
	glColor3f(0.0,1.0,1.0);
	drawstring(180.0,320.0,1.0," Parthasarathy M Alwar       1BY10CS049");
	
	glColor3f(1.0,1.0,1.0);
	drawstring(190.0,260.0,1.0,"UNDER THE GUIDANCE OF");
	
	glColor3f(0.0,1.0,1.0);
	drawstring(70.0,230.0,1.0," Guide ");

		setFont(GLUT_BITMAP_HELVETICA_12);

	glColor3f(0.0,1.0,1.0);
	drawstring(190.0,230.0,1.0," Guide Degrees .");		
	
	glColor3f(0.0,1.0,1.0);
	drawstring(70.0,215.0,1.0,"  Lecturer, Dept. of CS&E");

	glColor3f(0.0,1.0,1.0);
	drawstring(70.0,200.0,1.0,"  BMSIT");
  
	glFlush();
}
	




void draw_key_int(void)				// text for keyboard interaction

{

	glColor3f(0.0,0.0,0.0);
	glBegin(GL_POLYGON);
	glVertex2f(0,0);
	glVertex2f(0,135);
	glVertex2f(500,135);
	glVertex2f(500,0);
	glEnd();
	glFlush();


	glColor3f(1.0f,1.0f,1.0f);
	setFont(GLUT_BITMAP_HELVETICA_18);
	drawstring(360.0,130.0,1.0,"DO U WISH TO CONTINUE?");
	glColor3f(1.0f,1.0f,1.0f);
	drawstring(360.0,110.0,1.0,"PRESS  Y/N");
	glFlush();
}






void mykeyboard(unsigned char key,int x,int y)
{
	if(key=='y' || key=='Y')
	{
		
		draw();
		text();

	
	}
	else if(key=='N' || key=='n')
	{
		exit(0);
	}
}
	




void myMouse(int btn, int state, int x, int y)
{

	if(btn==GLUT_LEFT_BUTTON && state == GLUT_DOWN )
	{
		x=x/2;
		y=(1000-y)/2.1;
		if ((x>=180 && x<=305) && (y>=395 && y<=425 ))// 1 menu
		
		{
			;
		
		}
		
		if((x>=180 && x<=305) && (y>=354 && y<=375 ))//   2 menu
		{
			;
		 
		}
		if((x>=180 && x<=305) && (y>=311 && y<=333 ))  // 3 menu
		{
				;

		}

		if((x>=180 && x<=305) && (y>=269 && y<=293 ))  // 4 menu
		{
				;

		}

		if((x>=180 && x<=305) && (y>=226 && y<=249 ))  // 5 menu
		{
				;
		}

		if((x>=180 && x<=305) && (y>=183 && y<=206 ))  // 6 menu
		{
				exit(0);
		}
		
	}
}

void display(void)
{  

	glClear(GL_COLOR_BUFFER_BIT);
	title();
	delay();delay();delay();
	draw();
	text();
}



int main(int argc,char **argv)
{
	glutInit(&argc,argv);
	glutInitDisplayMode(GLUT_SINGLE|GLUT_RGBA);
  	glutInitWindowPosition(0,0);
	glutInitWindowSize(1000,1000);
	glutCreateWindow("GSM CALL SETUP");
    glutDisplayFunc(display);
	glutMouseFunc(myMouse);
	glutKeyboardFunc(mykeyboard);
	myInit();
	glutMainLoop();
    
return 1;
}
