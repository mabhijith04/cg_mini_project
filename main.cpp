#include<GL/glut.h>
#include<stdio.h>
#include<stdlib.h>
void *currentfont;
GLfloat x[25];
GLfloat y[20];
GLint i,j,k;
int w,h;
void setFont(void *font)
{ currentfont=font;
}
void drawstring(float x,float y,float z,char *str)
{	char *c;
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
{   glClearColor(0.0,0.0,0.0,0.0);
	glColor3f(0.0f,0.0f,0.0f);
	glPointSize(5.0);
	gluOrtho2D(0.0,500.0,0.0,500.0);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	setFont(GLUT_BITMAP_HELVETICA_18);
}
void draw_bts(GLint x,GLint y)
{ glBegin(GL_LINES);
   glColor3f(.5,.4,1);
   glVertex2d(x,y);
   glVertex2d(x+17,y+60+60);
  glEnd(); 
  glBegin(GL_LINES);
   glColor3f(.5,.4,1);
   glVertex2d(x+17,y+60+60);
   glVertex2d(x+30,y);
  glEnd();
  glBegin(GL_LINES);
   glColor3f(.5,.5,.5);
   glVertex2d(x+11,y+80);
   glVertex2d(x+21,y+80);
  glEnd();
  glBegin(GL_LINES);
   glColor3f(.5,.5,.5);
   glVertex2d(x+21,y+80);
   glVertex2d(x+6,y+40);
  glEnd();
  glBegin(GL_LINES);
   glColor3f(.5,.5,.5);
   glVertex2d(x+26,y+40);
   glVertex2d(x+11,y+80);
  glEnd();		
  glBegin(GL_LINES);
   glColor3f(.5,.5,.5);
   glVertex2d(x+6,y+40);
   glVertex2d(x+30,y);
  glEnd();
  glBegin(GL_LINES);
   glColor3f(.5,.5,.5);
   glVertex2d(x+26,y+40);
   glVertex2d(x,y);
  glEnd();
  glBegin(GL_LINES);
   glColor3f(.5,.5,.5);
   glVertex2d(x+6,y+40);
   glVertex2d(x+26,y+40);
  glEnd();
  //code for drawing signal lines
  /*glBegin(GL_LINES);
   glColor3f(.5,.5,.5);
   glVertex2d(x+10,y+122);
   glVertex2d(x+7,y+124);
   glVertex2d(x+7,y+124);
   glVertex2d(x+7,y+128);
   glVertex2d(x+7,y+128);
   glVertex2d(x+10,y+130);
   *///*/
  glEnd();
}  
void draw_bsc(GLint x,GLint y,int f)
{ 	glBegin(GL_QUADS);
		if(f)
 		glColor3d(0,0,1);
 		else
 		glColor3d(0,1,0);
 		glVertex2f(x,y);
		glVertex2f(x+80,y);
 		glVertex2f(x+80.0,y+80.0);
		glVertex2f(x,y+80);
	glEnd();

}
void move1()  //MOVEMENT OF FRAME
{	float i,j,temp=0.1;
    //move 1
     glColor3f(1.0,0.0,0.0);
	 drawstring(210.0,5.0,1.0,"Phone Sends packet on network");
     for(i=0;i<51;i=i+temp) //movement of data packet sidewise
	 {   glColor3f(1,0,0);
	     glBegin(GL_QUADS);
	 	    glVertex2i(95-i,60);glVertex2i(95-i,65);glVertex2i(90-i,65);glVertex2i(90-i,60);
         glEnd();
   	     glFlush();
         glColor3f(0,0,0);   // to remove traces create movement of frame in black
	     glBegin(GL_QUADS);
	      glVertex2i(90+5-i,60);glVertex2i(90+5-i,65);glVertex2i(85+5-i,65);glVertex2i(85+5-i,60);
   	     glEnd();
         glFlush();
	}
	glColor3f(0.0,1.0,0.0);
	drawstring(210.0,5.0,1.0,"Phone Sends packet on network");
	//move 2
	for(j=0;j<62;j=j+temp) //movement of data packet from top to down
	 {   glColor3f(1,0,0);
		 glBegin(GL_QUADS);
	  	   glVertex2i(40,70+j);glVertex2i(40,75+j);glVertex2i(45,75+j);glVertex2i(45,70+j);
    	 glEnd();
    	 glFlush();
    	 glColor3f(0,0,0);
	 	 glBegin(GL_QUADS);
	  		glVertex2i(40,69+j);glVertex2i(40,74+j);glVertex2i(45,74+j);glVertex2i(45,69+j);
    	 glEnd();
    	 glFlush();
	 }
	 glColor3f(0,0,0);
	 glBegin(GL_QUADS);
	 	glVertex2i(40,69+j);glVertex2i(40,74+j);glVertex2i(45,74+j);glVertex2i(45,69+j);
     glEnd();
     glFlush();
     glColor3f(0.0,0.0,0.0);
	 drawstring(210.0,5.0,1.0,"Phone Sends packet on network");
     glColor3f(1.0,0.0,0.0);
	 drawstring(210.0,5.0,1.0,"Packet is forwarded to the BSC");
	 //move 3
    for(i=0;i<57;i=i+temp) //movement of data packet sidewise
	 {   glColor3f(1,0,0);
		 glBegin(GL_QUADS);
	 	  glVertex2i(77+i,130-3);glVertex2i(77+i,135-3);glVertex2i(72+i,135-3);glVertex2i(72+i,130-3);
    	 glEnd();
    	 glFlush();
      	 glColor3f(0,0,0);   // to remove traces create movement of frame in black
		 glBegin(GL_QUADS);
	      glVertex2i(72+5+i,130-3);glVertex2i(72+5+i,135-3);glVertex2i(72+i,135-3);glVertex2i(72+i,130-3);
   		 glEnd();
    	 glFlush();
	}
	glColor3f(0.0,1.0,0.0);
	drawstring(210.0,5.0,1.0,"Packet is forwarded to the BSC");
	//move 4
	glColor3f(0.0,1.0,0.0);
   	drawstring(210.0,5.0,1.0,"Packet is forwarded to the BSC");
	for(j=0;j<122;j=j+temp) //movement of data packet from top to down
	 {   glColor3f(1,0,0);
		 glBegin(GL_QUADS);
	 		 glVertex2i(130,140+j);glVertex2i(130,145+j);glVertex2i(135,145+j);glVertex2i(135,140+j);
    	 glEnd();
    	 glFlush();
    	 glColor3f(0,0,0);
		 glBegin(GL_QUADS);
	  		glVertex2i(130,140+j);glVertex2i(130,145+j);glVertex2i(135,145+j);glVertex2i(135,140+j);
         glEnd();
    	 glFlush();
	 }
     for(j=0;j<5;j=j+temp) //movement of data packet from top to down
	 {	
	 	 glColor3f(0,0,0);
		 glBegin(GL_QUADS);
		  glVertex2i(130,260+j);glVertex2i(135,265+j);glVertex2i(130,265+j);glVertex2i(135,260+j);
    	 glEnd();
    	 glFlush();
     }
     draw_bsc(130,270,0);
     glColor3f(1.0f,1.0f,1.0f);
 	 drawstring(165.0,310.0,1.0,"BSC");
	 glColor3f(0.0,0.0,0.0);
	 drawstring(210.0,5.0,1.0,"Packet is forwarded to the BSC");
	 glColor3f(1.0,0.0,0.0);
	 drawstring(210.0,5.0,1.0,"The details of the SIM are to be fetched ");
    //move 5
    for(j=0;j<50;j=j+temp) //movement of data packet from top to down
	 {   glColor3f(1,0,0);
		 glBegin(GL_QUADS);
		  glVertex2i(130,354+j);glVertex2i(135,354+j);glVertex2i(135,359+j);glVertex2i(130,359+j);
    	 glEnd();
   		 glFlush();
		 glColor3f(0,0,0);
		 glBegin(GL_QUADS);
		  glVertex2i(130,352+j);glVertex2i(135,352+j);glVertex2i(135,357+j);glVertex2i(130,357+j);
    	 glEnd();
   	     glFlush();
	}
	for(j=0;j<5;j=j+temp) //movement of data packet from top to down
	 {	
	 	 glColor3f(0,0,0);
		 glBegin(GL_QUADS);
		  glVertex2i(130,402+j);glVertex2i(135,402+j);glVertex2i(130,407+j);glVertex2i(135,407+j);
    	 glEnd();
    	 glFlush();
    }
    glColor3f(0.0,1.0,0.0);
	drawstring(210.0,5.0,1.0,"The details of the SIM are to be fetched ");
    //move 6
    for(i=0;i<97;i=i+temp) //movement of data packet sidewise
	 {   glColor3f(1,0,0);
		 glBegin(GL_QUADS);
		  glVertex2i(132+i,406);glVertex2i(137+i,406);glVertex2i(137+i,411);glVertex2i(132+i,411);
    	 glEnd();
    	 glFlush();
      	 glColor3f(0,0,0);   // to remove traces create movement of frame in black
		 glBegin(GL_QUADS);
	  		glVertex2i(132+i,406);glVertex2i(137+i,406);glVertex2i(137+i,411);glVertex2i(132+i,411);
   		 glEnd();
    	 glFlush();
	}
	glColor3f(1.0,0.0,0.0);
	drawstring(210.0,5.0,1.0,"The details of the SIM are to be fetched ");
	//move 7
	for(j=0;j<50;j=j+temp) //movement of data packet from top to down
	 {   glColor3f(1,0,0);
		 glBegin(GL_QUADS);
		  glVertex2i(232,409-j);glVertex2i(232,404-j);glVertex2i(237,404-j);glVertex2i(237,409-j);
   		 glEnd();
   		 glFlush();
		 glColor3f(0,0,0);
		 glBegin(GL_QUADS);
		  glVertex2i(232,409-j);glVertex2i(232,404-j);glVertex2i(237,404-j);glVertex2i(237,409-j);
    	 glEnd();
   		 glFlush();
	}
	draw_bsc(230,270,0);
	//redraw//VLR inside
				glBegin(GL_POLYGON);
				 glColor3f(1,0.0,0.0);
				 glVertex2f(290,280);
				 glVertex2f(292,278);
				 glVertex2f(298,278);
				 glVertex2f(300,280);
				 glVertex2f(300,300);
				 glVertex2f(298,297);
				 glVertex2f(292,297);
				 glVertex2f(290,300);
				glEnd();
				glBegin(GL_LINE_LOOP); 
				 glColor3f(1.0,0.0,0.0);
				 glVertex2f(290,300);
				 glVertex2f(292,303);
				 glVertex2f(298,303);
				 glVertex2f(300,300);
				 glVertex2f(298,297);
				 glVertex2f(292,297);
				 glVertex2f(290,300);
				glEnd();
	//end redraw
 	glColor3f(1.0f,1.0f,1.0f);
 	drawstring(265.0,310.0,1.0,"MSC/VLR");
 	glColor3f(0.0,0.0,0.0);
	drawstring(210.0,5.0,1.0,"The details of the SIM are to be fetched ");
	glColor3f(0.0,1.0,0.0);
	drawstring(210.0,5.0,1.0,"Details not found as this is the first use.Fetch details from the data base (HLR) ");
	//move 8
	for(j=0;j<50;j=j+temp) //movement of data packet from top to down
	 {   glColor3f(1,0,0);
		 glBegin(GL_QUADS);
		  glVertex2i(305,357+j);glVertex2i(305,352+j);glVertex2i(310,352+j);glVertex2i(310,357+j);
   		 glEnd();
   		 glFlush();
	 	 glColor3f(0,0,0);
		 glBegin(GL_QUADS);
	 	  glVertex2i(305,357+j);glVertex2i(305,352+j);glVertex2i(310,352+j);glVertex2i(310,357+j);
    	 glEnd();
    	 glFlush();
	}
	glColor3f(1.0,0.0,0.0);
	drawstring(210.0,5.0,1.0,"Details not found as this is the first use.Fetch details from the data base (HLR) ");
	//move 9
    for(i=0;i<18;i=i+temp) //movement of data packet sidewise
	 {   glColor3f(1,0,0);
		 glBegin(GL_QUADS);
		  glVertex2i(312+i,407);glVertex2i(312+i,402);glVertex2i(317+i,402);glVertex2i(317+i,407);
    	 glEnd();
    	 glFlush();
      	 glColor3f(0,0,0);   // to remove traces create movement of frame in black
		 glBegin(GL_QUADS);
	  	  glVertex2i(312+i,407);glVertex2i(312+i,402);glVertex2i(317+i,402);glVertex2i(317+i,407);
    	 glEnd();
    	 glFlush();
	}
	glColor3f(0.0,0.0,0.0);
	drawstring(210.0,5.0,1.0,"Details not found as this is the first use.Fetch details from the data base (HLR) ");
	//move 10
	for(j=0;j<40;j=j+temp) //movement of data packet from top to down
	 {   glColor3f(1,0,0);
		 glBegin(GL_QUADS);
	      glVertex2i(335,397-j);glVertex2i(335,392-j);glVertex2i(340,392-j);glVertex2i(340,397-j);
    	 glEnd();
   		 glFlush();
	 	 glColor3f(0,0,0);
		 glBegin(GL_QUADS);
	  	  glVertex2i(335,397-j);glVertex2i(335,392-j);glVertex2i(340,392-j);glVertex2i(340,397-j);
   		 glEnd();
   		 glFlush();
	}
	draw_bsc(330,270,0);
	glColor3f(1.0f,1.0f,1.0f);
	drawstring(365.0,310.0,1.0,"HLR");
 	glColor3f(1.0,0.0,0.0);
	drawstring(210.0,5.0,1.0,"Details FOUND!! Return details to VLR and update location details of the subscriber  ");
	//move -10
	for(j=0;j<30;j=j+temp) //movement of data packet from top to down
	 {   glColor3f(0,1,0);
		 glBegin(GL_QUADS);
	  	  glVertex2i(335,397+j);glVertex2i(335,392+j);glVertex2i(340,392+j);glVertex2i(340,397+j);
    	 glEnd();
   		 glFlush();
		 glColor3f(0,0,0);
		 glBegin(GL_QUADS);
	 	  glVertex2i(335,397+j);glVertex2i(335,392+j);glVertex2i(340,392+j);glVertex2i(340,397+j);
    	 glEnd();
   		 glFlush();
	}
	//move -9
    for(i=0;i<18;i=i+temp) //movement of data packet sidewise
	 {   glColor3f(0,1,0);
		 glBegin(GL_QUADS);
		  glVertex2i(312-i,427);glVertex2i(312-i,422);glVertex2i(317-i,422);glVertex2i(317-i,427);
    	 glEnd();
   		 glFlush();
      	 glColor3f(0,0,0);   // to remove traces create movement of frame in black
		 glBegin(GL_QUADS);
	  	  glVertex2i(312-i,427);glVertex2i(312-i,422);glVertex2i(317-i,422);glVertex2i(317-i,427);
   		 glEnd();
   		 glFlush();
	}
    //move -8
	for(j=0;j<50;j=j+temp) //movement of data packet from top to down
	 {   glColor3f(0,1,0);
		 glBegin(GL_QUADS);
		  glVertex2i(294,407-j);glVertex2i(294,402-j);glVertex2i(299,402-j);glVertex2i(299,407-j);
   		 glEnd();
   		 glFlush();
	     glColor3f(0,0,0);
		 glBegin(GL_QUADS);
	 	  glVertex2i(294,407-j);glVertex2i(294,402-j);glVertex2i(299,402-j);glVertex2i(299,407-j);
   		 glEnd();
   		 glFlush();
	}
//move -7
	for(j=0;j<50;j=j+temp) //movement of data packet from top to down
	 {   glColor3f(0,1,0);
		 glBegin(GL_QUADS);
	  	 glVertex2i(232,355+j);glVertex2i(232,350+j);glVertex2i(237,350+j);glVertex2i(237,355+j);
    	 glEnd();
    	 glFlush();
	     glColor3f(0,0,0);
		 glBegin(GL_QUADS);
		  glVertex2i(232,355+j);glVertex2i(232,350+j);glVertex2i(237,350+j);glVertex2i(237,355+j);
   		 glEnd();
   		 glFlush();
	}
	//move -6
    for(i=0;i<97;i=i+temp) //movement of data packet sidewise
	 {   glColor3f(0,1,0);
		 glBegin(GL_QUADS);
	  	  glVertex2i(232-i,406);glVertex2i(237-i,406);glVertex2i(237-i,411);glVertex2i(232-i,411);
    	 glEnd();
   		 glFlush();
       	 glColor3f(0,0,0);   // to remove traces create movement of frame in black
		 glBegin(GL_QUADS);
  		  glVertex2i(232-i,406);glVertex2i(237-i,406);glVertex2i(237-i,411);glVertex2i(232-i,411);
    	 glEnd();
    	 glFlush();
	}
	//move -5
   for(j=0;j<48;j=j+temp) //movement of data packet from top to down
	 {   glColor3f(0,1,0);
		 glBegin(GL_QUADS);
	 	  glVertex2i(130,406-j);glVertex2i(135,406-j);glVertex2i(135,401-j);glVertex2i(130,401-j);
    	 glEnd();
    	 glFlush();
	 	 glColor3f(0,0,0);
		 glBegin(GL_QUADS);
	  	  glVertex2i(130,406-j);glVertex2i(135,406-j);glVertex2i(135,401-j);glVertex2i(130,401-j);
    	 glEnd();
    	 glFlush();
	}
	//move -4
	 for(j=0;j<122;j=j+temp) //movement of data packet from top to down
	 {   glColor3f(0,1,0);
		 glBegin(GL_QUADS);
	 	  glVertex2i(130,270-j);glVertex2i(135,270-j);glVertex2i(135,265-j);glVertex2i(130,265-j);
    	 glEnd();
    	 glFlush();
    	 glColor3f(0,0,0);
		 glBegin(GL_QUADS);
	 	  glVertex2i(130,270-j);glVertex2i(135,270-j);glVertex2i(135,265-j);glVertex2i(130,265-j);
    	 glEnd();
	     glFlush();
	}
    //move -3
   for(i=0;i<57;i=i+temp) //movement of data packet sidewise
	 {   glColor3f(0,1,0);
		 glBegin(GL_QUADS);
	  		glVertex2i(130-i,132);glVertex2i(130-i,127);glVertex2i(135-i,127);glVertex2i(135-i,132);
    	 glEnd();
    	 glFlush();
    	 glColor3f(0,0,0);   // to remove traces create movement of frame in black
		 glBegin(GL_QUADS);
	  		glVertex2i(130-i,132);glVertex2i(130-i,127);glVertex2i(135-i,127);glVertex2i(135,132);
    	 glEnd();
  	     glFlush();
	}
	//move -2
   for(j=0;j<50;j=j+temp) //movement of data packet from top to down
	 {  glColor3f(0,1,0);
		glBegin(GL_QUADS);
		  glVertex2i(45,130-j);glVertex2i(50,130-j);glVertex2i(50,125-j);glVertex2i(45,125-j);
 	    glEnd();
    	glFlush();
   		glColor3f(0,0,0);
	 	glBegin(GL_QUADS);
	   	 glVertex2i(45,130-j);glVertex2i(50,130-j);glVertex2i(50,125-j);glVertex2i(45,125-j);
    	glEnd();
    	glFlush();
	 }
	 //move -1
    for(i=0;i<40;i=i+temp) //movement of data packet sidewise
	 {   glColor3f(0,1,0);
		 glBegin(GL_QUADS);
	 		 glVertex2i(45+i,80);glVertex2i(45+i,75);glVertex2i(50+i,75);glVertex2i(50+i,80);
   		 glEnd();
    	 glFlush();
         glColor3f(0,0,0);   // to remove traces create movement of frame in black
		 glBegin(GL_QUADS);
		    glVertex2i(45+i,80);glVertex2i(45+i,75);glVertex2i(50+i,75);glVertex2i(50+i,80);
  		 glEnd();
   		 glFlush();
	}
}
void mobile_stn(int choice)		// to draw the sender and receiver MS
{ int j;int temp=5;
	switch(choice)
	{ case 1: 	glColor3f(1.0f,1.0f,1.0f);
				setFont(GLUT_BITMAP_HELVETICA_12);
 				drawstring(95.0,20.0,1.0,"SENDER");
 				glColor3f(1.0f,1.0f,1.0f);
 				drawstring(70.0,100.0,1.0,"BTS");
				/*Sender MS code*/
				glBegin(GL_QUADS);
         		 glColor3f(0.2,.2,0.2);
	 			 glVertex2f(75.0+20,30.0);
	 			 glVertex2f(100.0+20,30.0);
	 			 glVertex2f(100.0+20,90.0);
	 			 glVertex2f(75.0+20,90.0);
				glEnd();
				glBegin(GL_QUADS);
         		 glColor3f(.5,0.1,.4);
         		 glVertex2f(120,90);
	 			 glVertex2f(120,110);
	 			 glVertex2f(115,110);
	 			 glVertex2f(115,90);
				glEnd();
				glBegin(GL_QUADS);
         		 glColor3f(0,0,1);
         		 glVertex2f(100-3,80+4);
	 			 glVertex2f(100-3,60);
	 			 glVertex2f(115+3,60);
 	 			 glVertex2f(115+3,80+4);
				glEnd();
				//end of sender MS code
				draw_bts(45,130);
				draw_bsc(130,270,1);
				draw_bsc(230,270,1);
				draw_bsc(330,270,1);
				//draw vlr
				//VLR inside
				glBegin(GL_POLYGON);
				 glColor3f(1,1.0,0.0);
				 glVertex2f(290,280);
				 glVertex2f(292,278);
				 glVertex2f(298,278);
				 glVertex2f(300,280);
				 glVertex2f(300,300);
				 glVertex2f(298,297);
				 glVertex2f(292,297);
				 glVertex2f(290,300);
				glEnd();
				glBegin(GL_LINE_LOOP); 
				 glColor3f(1.0,1.0,0.0);
				 glVertex2f(290,300);
				 glVertex2f(292,303);
				 glVertex2f(298,303);
				 glVertex2f(300,300);
				 glVertex2f(298,297);
				 glVertex2f(292,297);
				 glVertex2f(290,300);
				glEnd(); 
			    // channel linking MSC and HLR
				glBegin(GL_POLYGON);
				 glColor3f(1,0.0,0.0);
				 glVertex2f(310,335);
				 glVertex2f(310,340);
				 glVertex2f(330,340);
				 glVertex2f(330,335);
				glEnd();
				// Authentication channel linking
				glBegin(GL_POLYGON);
				 glColor3f(1,0.0,0.0);
				 glVertex2f(310+100,335);
				 glVertex2f(310+100,340);
				 glVertex2f(330+100,340);
				 glVertex2f(330+100,335);
				glEnd();				 
				//end draw vlr
				glColor3f(1.0f,1.0f,1.0f);
 				drawstring(165.0,310.0,1.0,"BSC");
 				glColor3f(1.0f,1.0f,1.0f);
 				drawstring(265.0,310.0,1.0,"MSC/VLR");
 				glColor3f(1.0f,1.0f,1.0f);
 				drawstring(365.0,310.0,1.0,"HLR");
 				//draw auc
 				glBegin(GL_LINE_LOOP); 
				 glColor3f(1.0,0.0,0.0);
				 glVertex2f(430,340);
				glVertex2f(440,350);
				glVertex2f(450,350);
				glVertex2f(460,340);
				glVertex2f(450,330);
				glVertex2f(440,330);
				glVertex2f(430,340);
			   glEnd(); 
			   glBegin(GL_LINE_LOOP); 
				glColor3f(1.0,0.0,0.0);
				glVertex2f(430,340);
				glVertex2f(440,330);
				glVertex2f(450,330);
				glVertex2f(460,340);
				glVertex2f(460,323);
				glVertex2f(450,313);
				glVertex2f(440,313);
				glVertex2f(430,323);
				glVertex2f(430,340);
			   glEnd(); 
			   glBegin(GL_LINES);
				glColor3f(1.0,0.0,0.0);
				glVertex2f(440,330);
				glVertex2f(440,315);
			   glEnd();
			   glBegin(GL_LINES);
			    glColor3f(1.0,0.0,0.0);
				glVertex2f(450,330);
				glVertex2f(450,315);
		       glEnd();
			   glBegin(GL_LINES);
				glColor3f(0.0,1.0,0.0);
				glVertex2f(435,345);
				glVertex2f(455,335);
			   glEnd();
			   glBegin(GL_LINES);
				glColor3f(0.0,1.0,0.0);
				glVertex2f(455,345);
				glVertex2f(435,335);
			   glEnd();
 				//draw SIM
 				glBegin(GL_POLYGON);
      		    glColor3f(1.0,0.0,0.0);
        			glVertex2f(140,55);
					glVertex2f(140,75);
					glVertex2f(148,75);
					glVertex2f(148,60);
					glVertex2f(145,55);
				glEnd();
				//draw poygon on tower
				glBegin(GL_POLYGON);
				 glColor3f(1,0.0,0.0);
				 glVertex2f(61,268-20);
				 glVertex2f(59,270-20);
				 glVertex2f(59,272-20);
				 glVertex2f(61,274-20);
				 glVertex2f(63,274-20);
				 glVertex2f(65,272-20);
				 glVertex2f(65,270-20);
				 glVertex2f(63,268-20);
				glEnd();
 				move1();
 				break;
 	case 2:     glClear(GL_COLOR_BUFFER_BIT);
 				glColor3f(1.0f,1.0f,1.0f);
				setFont(GLUT_BITMAP_HELVETICA_12);
 				drawstring(95.0,20.0,1.0,"SENDER");
 				glColor3f(1.0f,1.0f,1.0f);
 				drawstring(56.0,115.0,1.0,"BTS");
				/*Sender MS code*/
				glBegin(GL_QUADS);
         		 glColor3f(0.2,.2,0.2);
	 			 glVertex2f(75.0+20,30.0);
	 			 glVertex2f(100.0+20,30.0);
	 			 glVertex2f(100.0+20,90.0);
	 			 glVertex2f(75.0+20,90.0);
				glEnd();
				glBegin(GL_QUADS);
         		 glColor3f(.5,0.1,.4);
         		 glVertex2f(120,90);
	 			 glVertex2f(120,110);
	 			 glVertex2f(115,110);
	 			 glVertex2f(115,90);
				glEnd();
			 	glBegin(GL_QUADS);
         	   	 glColor3f(0,0,1);
         		 glVertex2f(100-3,80+4);
	 			 glVertex2f(100-3,60);
	 			 glVertex2f(115+3,60);
 	 			 glVertex2f(115+3,80+4);
				glEnd();
				//end of sender MS code
				draw_bts(45,130);
				//draw poygon on tower
				glBegin(GL_POLYGON);
				 glColor3f(1,0.0,0.0);
				 glVertex2f(61,268-20);
				 glVertex2f(59,270-20);
				 glVertex2f(59,272-20);
				 glVertex2f(61,274-20);
				 glVertex2f(63,274-20);
				 glVertex2f(65,272-20);
				 glVertex2f(65,270-20);
				 glVertex2f(63,268-20);
				glEnd();
				draw_bsc(130,270,1);
				draw_bsc(230,270,1);
				draw_bsc(330,270,1);
				//draw vlr
				//VLR inside
				glBegin(GL_POLYGON);
				 glColor3f(1,1.0,0.0);
				 glVertex2f(290,280);
				 glVertex2f(292,278);
				 glVertex2f(298,278);
				 glVertex2f(300,280);
				 glVertex2f(300,300);
				 glVertex2f(298,297);
				 glVertex2f(292,297);
				 glVertex2f(290,300);
				glEnd();
				glBegin(GL_LINE_LOOP); 
				 glColor3f(1.0,1.0,0.0);
				 glVertex2f(290,300);
				 glVertex2f(292,303);
				 glVertex2f(298,303);
				 glVertex2f(300,300);
				 glVertex2f(298,297);
				 glVertex2f(292,297);
				 glVertex2f(290,300);
				glEnd(); 
			    // channel linking MSC and HLR
				glBegin(GL_POLYGON);
				 glColor3f(1,0.0,0.0);
				 glVertex2f(310,335);
				 glVertex2f(310,340);
				 glVertex2f(330,340);
				 glVertex2f(330,335);
				glEnd();
				// Authentication channel linking
				glBegin(GL_POLYGON);
				 glColor3f(1,0.0,0.0);
				 glVertex2f(310+100,335);
				 glVertex2f(310+100,340);
				 glVertex2f(330+100,340);
				 glVertex2f(330+100,335);
				glEnd();				 
				//end draw vlr
				//draw auc
 				glBegin(GL_LINE_LOOP); 
				 glColor3f(1.0,0.0,0.0);
				 glVertex2f(430,340);
				glVertex2f(440,350);
				glVertex2f(450,350);
				glVertex2f(460,340);
				glVertex2f(450,330);
				glVertex2f(440,330);
				glVertex2f(430,340);
			   glEnd(); 
			   glBegin(GL_LINE_LOOP); 
				glColor3f(1.0,0.0,0.0);
				glVertex2f(430,340);
				glVertex2f(440,330);
				glVertex2f(450,330);
				glVertex2f(460,340);
				glVertex2f(460,323);
				glVertex2f(450,313);
				glVertex2f(440,313);
				glVertex2f(430,323);
				glVertex2f(430,340);
			   glEnd(); 
			   glBegin(GL_LINES);
				glColor3f(1.0,0.0,0.0);
				glVertex2f(440,330);
				glVertex2f(440,315);
			   glEnd();
			   glBegin(GL_LINES);
			    glColor3f(1.0,0.0,0.0);
				glVertex2f(450,330);
				glVertex2f(450,315);
		       glEnd();
			   glBegin(GL_LINES);
				glColor3f(0.0,1.0,0.0);
				glVertex2f(435,345);
				glVertex2f(455,335);
			   glEnd();
			   glBegin(GL_LINES);
				glColor3f(0.0,1.0,0.0);
				glVertex2f(455,345);
				glVertex2f(435,335);
			   glEnd();
				glColor3f(1.0f,1.0f,1.0f);
 				drawstring(345.0,20.0,1.0,"RECEIVER");
				glColor3f(1.0f,1.0f,1.0f);
 				drawstring(462.0,100.0,1.0,"BTS");
				/*Reciever MS code*/
				glBegin(GL_QUADS);
     			 glColor3f(0.2,.2,0.2);
		   	     glVertex2f(250+75.0+20,30.0);
			     glVertex2f(250+100.0+20,30.0);
	 		     glVertex2f(250+100.0+20,90.0);
	 			 glVertex2f(250+75.0+20,90.0);
				glEnd();
				glBegin(GL_QUADS);
    		    glColor3f(.5,0.1,.4);
       	  	     glVertex2f(250+120,90);
	 			 glVertex2f(250+120,110);
	 			 glVertex2f(250+115,110);
				 glVertex2f(250+115,90);
			 	glEnd();
				glBegin(GL_QUADS);
         		glColor3f(0,0,1);
		         glVertex2f(250+100-3,80+4);
	  			 glVertex2f(250+100-3,60);
	 			 glVertex2f(250+115+3,60);
 	 			 glVertex2f(250+115+3,80+4);
				glEnd();
				//reciever BTS code
        		draw_bts(450,120);
				glColor3f(1.0f,1.0f,1.0f);
 				drawstring(165.0,310.0,1.0,"BSC");
 				glColor3f(1.0f,1.0f,1.0f);
 				drawstring(265.0,310.0,1.0,"MSC/VLR");
 				glColor3f(1.0f,1.0f,1.0f);
 				drawstring(365.0,310.0,1.0,"HLR");temp=5;
 				//draw poygon on tower
				glBegin(GL_POLYGON);
				 glColor3f(1,0.0,0.0);
				 glVertex2f(405+61,268-28);
				 glVertex2f(405+59,270-28);
				 glVertex2f(405+59,272-28);
				 glVertex2f(405+61,274-28);
				 glVertex2f(405+63,274-28);
				 glVertex2f(405+65,272-28);
				 glVertex2f(405+65,270-28);
				 glVertex2f(405+63,268-28);
				glEnd();
 				glFlush();
 				break;
	/*glColor3f(1.0f,1.0f,1.0f);
 	drawstring(345.0,20.0,1.0,"RECEIVER");
	glColor3f(1.0f,1.0f,1.0f);
 	drawstring(400.0,100.0,1.0,"BTS");
	/*Reciever MS code
	glBegin(GL_QUADS);
     glColor3f(0.2,.2,0.2);
	 glVertex2f(250+75.0+20,30.0);
	 glVertex2f(250+100.0+20,30.0);
	 glVertex2f(250+100.0+20,90.0);
	 glVertex2f(250+75.0+20,90.0);
	glEnd();
	glBegin(GL_QUADS);
         glColor3f(.5,0.1,.4);
         glVertex2f(250+120,90);
	 glVertex2f(250+120,110);
	 glVertex2f(250+115,110);
	 glVertex2f(250+115,90);
	glEnd();
	glBegin(GL_QUADS);
         glColor3f(0,0,1);
         glVertex2f(250+100-3,80+4);
	 glVertex2f(250+100-3,60);
	 glVertex2f(250+115+3,60);
 	 glVertex2f(250+115+3,80+4);
	glEnd();
	//sender BTS code
        draw_bts(60,120);
	//reciever BTS code
        draw_bts(390,120);
	//BSS code
	//VLR code
	//HLR code
	//any other code for drawing 
	}
	glFlush();
	*/
	}//end of switch
}
void delay()
{  j=20000;
   while(j!=0)
   { j--;
     i=20000;
     while(i!=0)
	i--;
   }
}
void title()												// to draw the starting screen
{	glClear(GL_COLOR_BUFFER_BIT);
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
{	glColor3f(0.0,0.0,0.0);
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
{  if(key=='y' || key=='Y')
	{
		draw();
		text();
	}
	else if(key=='N' || key=='n')
		exit(0);
}

void myMouse(int btn, int state, int x, int y)
{	if(btn==GLUT_LEFT_BUTTON && state == GLUT_DOWN )
	{
		x=x/2;
		y=(1000-y)/2.1;
		if ((x>=180 && x<=305) && (y>=395 && y<=425 ))// 1 menu
		{	glClear(GL_COLOR_BUFFER_BIT);
     		glColor3f(1.0,1.0,1.0);
			mobile_stn(1);
			draw_key_int();
		}
		if((x>=180 && x<=305) && (y>=354 && y<=375 ))//   2 menu
		{	glClear(GL_COLOR_BUFFER_BIT);
			glColor3f(1.0,1.0,1.0);
			mobile_stn(2);
			draw_key_int();
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

		if((x>=180 && x<=305) && (y>=183+24 && y<=206+24 ))  // 6 menu
		{
				exit(0);
		}
	}
}
void display(void)
{ 	glClear(GL_COLOR_BUFFER_BIT);
	title();
	delay();
	glClear(GL_COLOR_BUFFER_BIT);
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
