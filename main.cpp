#include<GL/glut.h>
#include<stdio.h>
#include<math.h>
#include<string>
int i;
bool show=false;
double s=.8,t=.2,c=.1,l=0.5;
float tx=0.0,scale=0.1,cx=0.0,sx=0.0,ty=0.0,twy=0.0,twx=0.0,tc=0.0,mx=0.0,ang=0.0;
bool objectVisible=false,objectVisible2=false;
int startTime=0,startTime1=0,startTime2=0;

void init () {
// Set "clearing" or background color
glClearColor(1,1,1,1);
gluOrtho2D(0.0, 1500.0, 0.0, 750.0);
}

void timer(int value) {
    // Update the current time elapsed
    int currentTime = glutGet(GLUT_ELAPSED_TIME);

    // Determine when the object should become visible (e.g., after 3 seconds)
    if (currentTime - startTime >= 20000) {
        objectVisible = true;
    }

    glutPostRedisplay();  // Trigger scene redraw
    glutTimerFunc(16, timer, 0);  // Call the timer function every 16 milliseconds (approximately 60 FPS)
}
void timer2(int value) {
    // Update the current time elapsed
    int currentTime1 = glutGet(GLUT_ELAPSED_TIME);

    // Determine when the object should become visible (e.g., after 3 seconds)
    if (currentTime1 - startTime1 >= 40000) {
        objectVisible2 = true;
    }

    glutPostRedisplay();  // Trigger scene redraw
    glutTimerFunc(16, timer2, 0);  // Call the timer function every 16 milliseconds (approximately 60 FPS)
}
void displayText()
{
    int currentTime2=glutGet(GLUT_ELAPSED_TIME);
    int elapsedTime=currentTime2-startTime2;
    glColor3f(0.0,0.0,0.0);
    glRasterPos2d(40,630);
    const char* subtitle;
    if (elapsedTime < 10000) {
    subtitle= "Animation showing sources of environmental Pollution";
    } else if (elapsedTime>10000 && elapsedTime<20000) {
    subtitle= "We can see building emitting gases, smoke emission from vehicles and hazardous waste from industries !";
    } else if(elapsedTime>20000 && elapsedTime<40000){
    subtitle= "Suddenly! A man comes crossing the road and throws waste into water even though there is a dustbin";
    }
    else if(elapsedTime>40000 && elapsedTime<45000){
        subtitle="We can also see another man on the other side of the road trying to cut tree !!";
    }
    else if(elapsedTime>45000 && elapsedTime<55000){
        subtitle="So it is evident that human activities has significantly contributed to environmental pollution!";
    }
    else if(elapsedTime>55000 && elapsedTime<60000){
        subtitle="But, It is not too late to make a difference.";
    }
    else if(elapsedTime>60000 && elapsedTime<66000){
        subtitle="Through collective efforts, we can protect and restore the environment, ensuring a brighter and greener future for generations to come.";
    }
    else{
        subtitle="Thank You for watching!!!";
    }

    // Render the subtitle text
     for (const char* c = subtitle; *c != '\0'; ++c) {
        glutBitmapCharacter(GLUT_BITMAP_HELVETICA_18, *c);  // Render each character
    }


}
void RiverLines()
{
    glPushMatrix();
    glTranslatef(tx,0,0);
    glEnable(GL_LINE_STIPPLE);
    glColor3f(0.0,0.5,1.0);
    glLineWidth(3.0);
glLineStipple(1, 0x0C0F); // glLineStipple(repeatFactor, pattern)
glBegin(GL_LINES); //(Forms line between P1 and P2, P3 and P4, P5 and P6...)
glVertex2d(-1500,60); //P1
glVertex2d(1499,60); //P2
glVertex2d(-1500,30);
glVertex2d(1499,30);
glVertex2d(-1500,90);
glVertex2d(1499,90);
glVertex2d(-1500,120);
glVertex2d(1499,120);
glDisable(GL_LINE_STIPPLE);
glEnd();
glPopMatrix();
tx+=0.05;
if(tx>1500)
    tx=0;
glutPostRedisplay();

}
void RoadLines()
{
    glEnable(GL_LINE_STIPPLE);
    glColor3f(1.0,1.0,1.0);
    glLineWidth(2.0);
glLineStipple(2, 0x00FF); // glLineStipple(repeatFactor, pattern)
glBegin(GL_LINES); //(Forms line between P1 and P2, P3 and P4, P5 and P6...)
glVertex2d(0,265); //P1
glVertex2d(1499,265); //P2
glDisable(GL_LINE_STIPPLE);
glEnd();
}
void sun(double x, double y)
{
    glBegin(GL_TRIANGLE_FAN);
        for(i=0;i<360;i++)
        {
            x=x+cos((i*3.14)/180)*s;
            y=y+sin((i*3.14)/180)*s;
            glVertex2d(x,y);

        }
    glEnd();
}
void circle(double x, double y)
{
    glBegin(GL_TRIANGLE_FAN);
        for(i=0;i<360;i++)
        {
            x=x+cos((i*3.14)/180)*c;
            y=y+sin((i*3.14)/180)*c;
            glVertex2d(x,y);

        }
    glEnd();
}
void cloud(double x, double y)
{
    glBegin(GL_TRIANGLE_FAN);
        for(i=0;i<360;i++)
        {
            x=x+cos((i*3.14)/180)*l;
            y=y+sin((i*3.14)/180)*l;
            glVertex2d(x,y);

        }
    glEnd();
}
void tyre(double x, double y)
{
    glColor3f(0.0,0.0,0.0);
    glBegin(GL_TRIANGLE_FAN);
        for(i=0;i<360;i++)
        {
            x=x+cos((i*3.14)/180)*t;
            y=y+sin((i*3.14)/180)*t;
            glVertex2d(x,y);

        }
    glEnd();
}
void car()
{
    glBegin(GL_POLYGON);
    glColor3f(1.0,0.0,0.0);
    glVertex2d(200,265);
    glVertex2d(200,315);
    glVertex2d(350,315);
    glVertex2d(350,265);
    glEnd();

    glBegin(GL_POLYGON);
    glColor3f(0.0,0.5,1.0);
    glVertex2d(220,315);
    glVertex2d(330,315);
    glVertex2d(320,335);
    glVertex2d(230,335);
    glEnd();

    glBegin(GL_POLYGON);
    glColor3f(0,0,0);
    glVertex2d(195,265);
    glVertex2d(200,265);
    glVertex2d(200,270);
    glVertex2d(195,270);
    glEnd();



}
void building()
{
    glColor3f(0.8,0.0,0.4);
    glBegin(GL_POLYGON);
    glVertex2d(1300,340);
    glVertex2d(1499,340);
    glVertex2d(1499,620);
    glVertex2d(1300,620);
    glEnd();

    glBegin(GL_POLYGON);
    glColor3f(0.1,0.0,0.5);
    glVertex2d(1100,340);
    glVertex2d(1100,580);
    glVertex2d(1300,580);
    glVertex2d(1300,340);
    glEnd();

     //blue chimney
    glBegin(GL_POLYGON);
    glColor3f(0.1,0.0,0.5);
    glVertex2d(1130,580);
    glVertex2d(1160,580);
    glVertex2d(1150,640);
    glVertex2d(1140,640);
    glEnd();

    //red chimney
    glColor3f(0.8,0.0,0.4);
    glBegin(GL_POLYGON);
    glVertex2d(1330,620);
    glVertex2d(1360,620);
    glVertex2d(1350,690);
    glVertex2d(1340,690);
    glEnd();

    //Blue door
    glColor3f(0.1,0.8,0.8);
    glBegin(GL_POLYGON);
    glVertex2d(1180,340);
    glVertex2d(1220,340);
    glVertex2d(1220,440);
    glVertex2d(1180,440);
    glEnd();

    //Blue window1
    glColor3f(0.1,0.8,0.8);
    glBegin(GL_POLYGON);
    glVertex2d(1120,460);
    glVertex2d(1160,460);
    glVertex2d(1160,500);
    glVertex2d(1120,500);
    glEnd();

    //Blue window2
    glColor3f(0.1,0.8,0.8);
    glBegin(GL_POLYGON);
    glVertex2d(1240,460);
    glVertex2d(1280,460);
    glVertex2d(1280,500);
    glVertex2d(1240,500);
    glEnd();

    //Blue window3
    glColor3f(0.1,0.8,0.8);
    glBegin(GL_POLYGON);
    glVertex2d(1120,520);
    glVertex2d(1160,520);
    glVertex2d(1160,560);
    glVertex2d(1120,560);
    glEnd();

    //Blue window4
    glColor3f(0.1,0.8,0.8);
    glBegin(GL_POLYGON);
    glVertex2d(1240,520);
    glVertex2d(1280,520);
    glVertex2d(1280,560);
    glVertex2d(1240,560);
    glEnd();

    //pink door
    glColor3f(0.8,0.5,0.8);
    glBegin(GL_POLYGON);
    glVertex2d(1379.5,340);
    glVertex2d(1419.5,340);
    glVertex2d(1419.5,460);
    glVertex2d(1379.5,460);
    glEnd();

    //pink window1
    glColor3f(0.8,0.5,0.8);
    glBegin(GL_POLYGON);
    glVertex2d(1320,480);
    glVertex2d(1360,480);
    glVertex2d(1360,520);
    glVertex2d(1320,520);
    glEnd();

    //pink window2
    glColor3f(0.8,0.5,0.8);
    glBegin(GL_POLYGON);
    glVertex2d(1439,480);
    glVertex2d(1479,480);
    glVertex2d(1479,520);
    glVertex2d(1439,520);
    glEnd();

    //pink window3
    glColor3f(0.8,0.5,0.8);
    glBegin(GL_POLYGON);
    glVertex2d(1320,540);
    glVertex2d(1360,540);
    glVertex2d(1360,580);
    glVertex2d(1320,580);
    glEnd();

    //pink window4
    glColor3f(0.8,0.5,0.8);
    glBegin(GL_POLYGON);
    glVertex2d(1439,540);
    glVertex2d(1479,540);
    glVertex2d(1479,580);
    glVertex2d(1439,580);
    glEnd();

    //toxic chemicals
    glBegin(GL_QUADS);
    glColor3f(0.0,0.0,0.0);
    glVertex2d(900,340);
    glVertex2d(950,340);
    glVertex2d(950,400);
    glVertex2d(900,400);
    glEnd();

    glBegin(GL_QUADS);
    glColor3f(1.0,0.0,0.0);
    glVertex2d(960,340);
    glVertex2d(1010,340);
    glVertex2d(1010,400);
    glVertex2d(960,400);
    glEnd();

    glBegin(GL_QUADS);
    glColor3f(0.0,0.5,0.0);
    glVertex2d(1020,340);
    glVertex2d(1070,340);
    glVertex2d(1070,400);
    glVertex2d(1020,400);
    glEnd();



}
void tree()
{
    glBegin(GL_QUADS);
    glColor3ub(139,69,19);
    glVertex2d(250,340);
    glVertex2d(250,500);
    glVertex2d(260,500);
    glVertex2d(260,340);
    glEnd();
    glColor3ub(0,128,0);
    sun(255,450);
    sun(230,420);
    sun(280,420);


}
void man()
{
    glPushMatrix();
    glTranslatef(0.0,ty,0.0);
    //hair
    glBegin(GL_POLYGON);
    double xh=150;
    double yh=400;
    glColor3f(0.0,0.0,0.0);
        for(i=0;i<360;i++)
        {
            xh=xh+cos((i*3.14)/180)*0.3;
            yh=yh+sin((i*3.14)/180)*0.3;
            glVertex2d(xh,yh);

        }
    glEnd();

    //face
    glBegin(GL_POLYGON);
    double xf=150;
    double yf=400;
    glColor3f(0.8,0.6,0.4);
        for(i=0;i<360;i++)
        {
            xf=xf+cos((i*3.14)/180)*0.2;
            yf=yf+sin((i*3.14)/180)*0.2;
            glVertex2d(xf,yf);

        }
    glEnd();

    //neck
    glBegin(GL_POLYGON);
    glColor3f(0.8,0.6,0.4);
    glVertex2d(145,399.6);
    glVertex2d(152,399.6);
    glVertex2d(152,394);
    glVertex2d(145,394);
    glEnd();

    //body
    glBegin(GL_POLYGON);
    glColor3f(1.0,0.0,0.0);
    glVertex2d(135,394);
    glVertex2d(162,394);
    glVertex2d(172,390);
    glVertex2d(169,387);
    glVertex2d(162,389);
    glVertex2d(162,369);
    glVertex2d(135,369);
    glVertex2d(135,390);
    glVertex2d(128,387);
    glVertex2d(125,390);
    glEnd();

    //skirt
    glBegin(GL_POLYGON);
    glColor3f(0.2,0.1,0.4);
    glVertex2d(135,369);
    glVertex2d(162,369);
    glVertex2d(164,351);
    glVertex2d(133,351);
    glEnd();

    //left leg
    glBegin(GL_POLYGON);
    glColor3f(0.8,0.6,0.4);
    glVertex2d(141,351);
    glVertex2d(146,351);
    glVertex2d(146,341);
    glVertex2d(141,341);
    glEnd();

    //right leg
    glBegin(GL_POLYGON);
    glColor3f(0.8,0.6,0.4);
    glVertex2d(151,351);
    glVertex2d(156,351);
    glVertex2d(156,341);
    glVertex2d(151,341);
    glEnd();

    //left shoe
    glBegin(GL_POLYGON);
    glColor3f(0.0,0.0,0.0);
    glVertex2d(141,341);
    glVertex2d(146,341);
    glVertex2d(146,336);
    glVertex2d(135,336);
    glEnd();

    //right shoe
    glBegin(GL_POLYGON);
    glColor3f(0.0,0.0,0.0);
    glVertex2d(151,341);
    glVertex2d(156,341);
    glVertex2d(162,336);
    glVertex2d(151,336);
    glEnd();

    //left hand
    glBegin(GL_POLYGON);
    glColor3f(0.8,0.6,0.4);
    glVertex2d(115,380);
    glVertex2d(125,390);
    glVertex2d(128,387);
    glVertex2d(118,377);
    glEnd();

    //right hand
    glBegin(GL_POLYGON);
    glColor3f(0.8,0.6,0.4);
    glVertex2d(172,390);
    glVertex2d(182,380);
    glVertex2d(179,377);
    glVertex2d(169,387);
    glEnd();

    //eyes
     glBegin(GL_POLYGON);
    double xe=146;
    double ye=411;
    glColor3f(0.0,0.0,0.0);
        for(i=0;i<360;i++)
        {
            xe=xe+cos((i*3.14)/180)*0.03;
            ye=ye+sin((i*3.14)/180)*0.03;
            glVertex2d(xe,ye);

        }
    glEnd();

    //eyes right
    glBegin(GL_POLYGON);
    double xe1=156;
    double ye1=411;
    glColor3f(0.0,0.0,0.0);
        for(i=0;i<360;i++)
        {
            xe1=xe1+cos((i*3.14)/180)*0.03;
            ye1=ye1+sin((i*3.14)/180)*0.03;
            glVertex2d(xe1,ye1);

        }
    glEnd();

    //mouth
    glBegin(GL_LINES);
    glColor3f(0.0,0.0,0.0);
    glVertex2d(146,408);
    glVertex2d(156,408);
    glEnd();


    glPopMatrix();
    ty-=0.05;
    if(ty<-170)
        ty=-180;

}
void man2()
{
    glBegin(GL_POLYGON);
    double xh=150;
    double yh=400;
    glColor3f(0.0,0.0,0.0);
        for(i=0;i<360;i++)
        {
            xh=xh+cos((i*3.14)/180)*0.3;
            yh=yh+sin((i*3.14)/180)*0.3;
            glVertex2d(xh,yh);

        }
    glEnd();

    //face
    glBegin(GL_POLYGON);
    double xf=150;
    double yf=400;
    glColor3f(0.8,0.6,0.4);
        for(i=0;i<360;i++)
        {
            xf=xf+cos((i*3.14)/180)*0.2;
            yf=yf+sin((i*3.14)/180)*0.2;
            glVertex2d(xf,yf);

        }
    glEnd();

    //neck
    glBegin(GL_POLYGON);
    glColor3f(0.8,0.6,0.4);
    glVertex2d(145,399.6);
    glVertex2d(152,399.6);
    glVertex2d(152,394);
    glVertex2d(145,394);
    glEnd();

    //body
    glBegin(GL_POLYGON);
    glColor3f(1.0,0.0,0.0);
    glVertex2d(135,394);
    glVertex2d(162,394);
    glVertex2d(172,390);
    glVertex2d(169,387);
    glVertex2d(162,389);
    glVertex2d(162,369);
    glVertex2d(135,369);
    glVertex2d(135,390);
    glVertex2d(128,387);
    glVertex2d(125,390);
    glEnd();

    //skirt
    glBegin(GL_POLYGON);
    glColor3f(0.2,0.1,0.4);
    glVertex2d(135,369);
    glVertex2d(162,369);
    glVertex2d(164,351);
    glVertex2d(133,351);
    glEnd();

    //left leg
    glBegin(GL_POLYGON);
    glColor3f(0.8,0.6,0.4);
    glVertex2d(141,351);
    glVertex2d(146,351);
    glVertex2d(146,341);
    glVertex2d(141,341);
    glEnd();

    //right leg
    glBegin(GL_POLYGON);
    glColor3f(0.8,0.6,0.4);
    glVertex2d(151,351);
    glVertex2d(156,351);
    glVertex2d(156,341);
    glVertex2d(151,341);
    glEnd();

    //left shoe
    glBegin(GL_POLYGON);
    glColor3f(0.0,0.0,0.0);
    glVertex2d(141,341);
    glVertex2d(146,341);
    glVertex2d(146,336);
    glVertex2d(135,336);
    glEnd();

    //right shoe
    glBegin(GL_POLYGON);
    glColor3f(0.0,0.0,0.0);
    glVertex2d(151,341);
    glVertex2d(156,341);
    glVertex2d(162,336);
    glVertex2d(151,336);
    glEnd();

    //left hand
    glBegin(GL_POLYGON);
    glColor3f(0.8,0.6,0.4);
    glVertex2d(115,380);
    glVertex2d(125,390);
    glVertex2d(128,387);
    glVertex2d(118,377);
    glEnd();

    //right hand
    glBegin(GL_POLYGON);
    glColor3f(0.8,0.6,0.4);
    glVertex2d(172,390);
    glVertex2d(182,380);
    glVertex2d(179,377);
    glVertex2d(169,387);
    glEnd();

    //eyes
     glBegin(GL_POLYGON);
    double xe=146;
    double ye=411;
    glColor3f(0.0,0.0,0.0);
        for(i=0;i<360;i++)
        {
            xe=xe+cos((i*3.14)/180)*0.03;
            ye=ye+sin((i*3.14)/180)*0.03;
            glVertex2d(xe,ye);

        }
    glEnd();

    //eyes right
    glBegin(GL_POLYGON);
    double xe1=156;
    double ye1=411;
    glColor3f(0.0,0.0,0.0);
        for(i=0;i<360;i++)
        {
            xe1=xe1+cos((i*3.14)/180)*0.03;
            ye1=ye1+sin((i*3.14)/180)*0.03;
            glVertex2d(xe1,ye1);

        }
    glEnd();

    //mouth
    glBegin(GL_LINES);
    glColor3f(0.0,0.0,0.0);
    glVertex2d(146,408);
    glVertex2d(156,408);
    glEnd();

    //axe
    glBegin(GL_QUADS);
    glColor3f(0.0,0.0,0.0);
    glVertex2d(180,378);
    glVertex2d(200,382);
    glVertex2d(201,380);
    glVertex2d(181,376);

    glVertex2d(202,370);
    glVertex2d(199,392);
    glVertex2d(204,393);
    glVertex2d(205,380);
    glEnd();



}
void handWaste()
{
    glPushMatrix();
    glTranslatef(twx,twy,0.0);
    //hand waste
    glBegin(GL_TRIANGLES);
    glColor3f(0.0,0.0,0.0);
    glVertex2d(180.5,378.5);
    glVertex2d(175.5,360);
    glVertex2d(200,380);
    glEnd();
    glPopMatrix();
    twy-=0.05;
    if(twy<-170)
        twy-=0.05;
    if(twy<-250){
        twy=-300;
        twx+=0.05;
    }

}
void display1()
{
    glClear(GL_COLOR_BUFFER_BIT);
    char text1[]="COMPUTER GRAPHICS MINI PROJECT";
    int i,len1;
    glColor3f(0.0,0.0,0.0);
    glRasterPos2f(500,600);
    len1=(int)strlen(text1);
    for(i=0;i<len1;i++){
        glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24,text1[i]);
    }
    char text2[]="TOPIC: ENVIRONMENTAL POLLUTION";
    glColor3f(0.0,0.0,1.0);
    glRasterPos2f(550,520);
    len1=(int)strlen(text2);
    for(i=0;i<len1;i++){
        glutBitmapCharacter(GLUT_BITMAP_HELVETICA_18,text2[i]);
    }
    char text3[]="TEAM MEMBERS:";
    glColor3f(1.0,0.0,0.0);
    glRasterPos2f(500,400);
    len1=(int)strlen(text3);
    for(i=0;i<len1;i++){
        glutBitmapCharacter(GLUT_BITMAP_HELVETICA_18,text3[i]);
    }
    char text4[]="Chandini R - 4SO20CS032";
    glColor3f(1.0,0.0,0.0);
    glRasterPos2f(500,370);
    len1=(int)strlen(text4);
    for(i=0;i<len1;i++){
        glutBitmapCharacter(GLUT_BITMAP_HELVETICA_18,text4[i]);
    }
    char text5[]="Deena Marina Dsouza - 4SO20CS037";
    glColor3f(1.0,0.0,0.0);
    glRasterPos2f(500,340);
    len1=(int)strlen(text5);
    for(i=0;i<len1;i++){
        glutBitmapCharacter(GLUT_BITMAP_HELVETICA_18,text5[i]);
    }
    char text6[]="Press 1 to go to next window";
    glColor3f(0.0,0.5,0.0);
    glRasterPos2f(500,200);
    len1=(int)strlen(text6);
    for(i=0;i<len1;i++){
        glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24,text6[i]);
    }
    glFlush();
}
void display()
{
glClear(GL_COLOR_BUFFER_BIT);
//River
glColor3f(0.6,0.9,1.0);
glBegin(GL_POLYGON);
glVertex2d(0,0);
glVertex2d(1500,0);
glVertex2d(1500,150);
glVertex2d(0,150);
glEnd();
RiverLines();
glDisable(GL_LINE_STIPPLE);

//Land1
glColor3ub(139,69,19);
glBegin(GL_POLYGON);
glVertex2d(0,150);
glVertex2d(1500,150);
glVertex2d(1500,200);
glVertex2d(0,200);
glEnd();

//Road
glColor3f(0.5,0.5,0.5);
glBegin(GL_POLYGON);
glVertex2d(0,200);
glVertex2d(1500,200);
glVertex2d(1500,330);
glVertex2d(0,330);
glEnd();

//Road Lines1
glBegin(GL_POLYGON);
glColor3f(1.0,1.0,1.0);
glVertex2d(0,200); //P1
glVertex2d(1500,200); //P2
glVertex2d(1500,210); //P3
glVertex2d(0,210); //P4
glEnd();

//Road Lines2
glBegin(GL_POLYGON);
glColor3f(1.0,1.0,1.0);
glVertex2d(0,330); //P1
glVertex2d(1500,330); //P2
glVertex2d(1500,340); //P3
glVertex2d(0,340); //P4
glEnd();

RoadLines();
glDisable(GL_LINE_STIPPLE);

//Sky
glBegin(GL_POLYGON);
glColor3f(0.5,0.8,1.0);
glVertex2d(0,750);
glVertex2d(1500,750);
glVertex2d(1500,600);
glVertex2d(0,600);
glEnd();

//Sun
   glColor3ub(255,215,0);
    sun(90,650);

   //MainLand
   glShadeModel(GL_SMOOTH);
   glBegin(GL_POLYGON);
   glColor3ub(255,215,0);
   glVertex2d(0,340);
   glVertex2d(1500,340);
   glColor3ub(0,100,0);
   glVertex2d(1500,590);
   glVertex2d(0,590);
   glEnd();

    //Car
    glPushMatrix();
    glTranslatef(tc,0,0);
    car();
    tyre(230,255);
    tyre(320,255);
    glPopMatrix();
    tc+=0.1;
    if(tc>1500)
        tc=-300;
    glutPostRedisplay();

    //Building
    building();

        //Dustbin
    glColor3f(0.0,0.5,0.0);
    glBegin(GL_POLYGON);
    glVertex2d(1320,150);
    glVertex2d(1380,150);
    glVertex2d(1400,250);
    glVertex2d(1300,250);
    glEnd();

    //dustbin text
    char string[]="Dustbin";
    int i,len;
    glColor3f(1.0,1.0,1.0);
    glRasterPos2f(1325,200);
    len=(int)strlen(string);
    for(i=0;i<len;i++){
        glutBitmapCharacter(GLUT_BITMAP_8_BY_13,string[i]);
    }
    //waste
    glColor3f(0.0,0.0,0.0);
    circle(1320,250);
    circle(1340,250);
    circle(1360,250);
    circle(1380,250);
    circle(1400,160);
    circle(1420,160);
    circle(1420,180);

    //waste in water
    glPushMatrix();
    glTranslatef(tx,0.0,0.0);
    circle(1420,120);
    circle(1440,120);
    glPopMatrix();
    tx+=0.05;
    if(tx>800)
        tx=0.0;

    //smoke
    glPushMatrix();
    glTranslatef(cx,0,0);
    glColor4f(0.5,0.5,0.5,0.5);
    cloud(1130,650);
    cloud(1145,660);
    cloud(1155,650);

    cloud(1330,690);
    cloud(1345,700);
    cloud(1355,690);
    glPopMatrix();
    cx-=0.5;
    if(cx<-150)
        cx=0;
    glutPostRedisplay();

    //car smoke
    glPushMatrix();
    glTranslatef(sx,0,0);
    glColor4f(0.0,0.0,0.0,0.0);
    circle(180,265);
    circle(185,270);
    circle(190,265);
    glPopMatrix();
    sx-=0.2;

    tree();


    //Text for waste
    char string1[]="Toxic";
    glColor3f(1.0,1.0,1.0);
    glRasterPos2f(905,370);
    len=(int)strlen(string1);
    for(i=0;i<len;i++){
        glutBitmapCharacter(GLUT_BITMAP_8_BY_13,string1[i]);
    }

    char string2[]="Toxic";
    glColor3f(1.0,1.0,0.0);
    glRasterPos2f(965,370);
    len=(int)strlen(string2);
    for(i=0;i<len;i++){
        glutBitmapCharacter(GLUT_BITMAP_8_BY_13,string2[i]);
    }

    char string3[]="Hazard";
    glColor3f(0.0,0.0,0.0);
    glRasterPos2f(1021,370);
    len=(int)strlen(string3);
    for(i=0;i<len;i++){
        glutBitmapCharacter(GLUT_BITMAP_8_BY_13,string3[i]);
    }


    if(objectVisible){
    man();
    handWaste();
    }

    if(objectVisible2){
    glPushMatrix();
    glTranslatef(mx,0.0,0.0);
    man2();
    glPopMatrix();
    mx+=0.05;
    if(mx>50.0)
        mx=51.0;
    }

    displayText();

    glFlush();
    glutSwapBuffers();
}
void keys(unsigned char key,int x,int y){
    if(key=='1'){
        show=true;
    }
}
void timer3(int value)
{

    if(show){
        glutDisplayFunc(display);
        glutPostRedisplay();
    }
    glutTimerFunc(100,timer3,0);
}
int main(int argc, char **argv)
{
glutInit(&argc, argv); // initialize glut library
glutInitDisplayMode(GLUT_SINGLE|GLUT_RGB); // single buffered mode with RGB colour variants
glutInitWindowSize(1500, 750); // 500 by 500 window size
glutInitWindowPosition(0,0); // where do you wanna see your window
glutCreateWindow("Environmental Pollution"); // the title of your window
init();// initialize the canvas
startTime = glutGet(GLUT_ELAPSED_TIME);
glutKeyboardFunc(keys);
glutDisplayFunc(display1); // call display function
glutTimerFunc(100,timer3,0);
glutTimerFunc(0, timer, 0);
glutTimerFunc(0,timer2,0);
glutMainLoop(); // run forever
}
