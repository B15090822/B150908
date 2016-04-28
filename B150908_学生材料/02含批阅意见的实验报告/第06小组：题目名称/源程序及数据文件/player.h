/* ��player.h�ļ����������� */
#ifndef _PLAYER             /*�������룬��ֹ�ظ������Ĵ���*/
#define _PLAYER
#include <string.h>
#define NUM 15               /*������Ա�����������˴����Ը���ʵ����Ҫ�޸ĳ���ֵ*/
struct Player                   /*��Ա��¼��������*/
{
 		int number;
  		char name[20];
 		int rank;
     	int score[5];
 		int assist[5];
 	    int rebounds[5];
 		int steals[5];
        int turnover[5];
        int total;
 };
 typedef struct Player Player;

 #define sizePla sizeof(Player)      /*һ����Ա��¼����Ҫ���ڴ�ռ��С*/
 int readPla(Player pla[],int n);       /*������Ա��¼ֵ��ѧ��Ϊ0������涨������¼ʱֹͣ*/
 void printPla(Player  *pla , int n);   /*���������Ա��¼��ֵ*/
 
  
 
 int equal(Player pla1,Player pla2,int condition);  /*����condition�����ж�����Player����������ȷ�*/
 int larger(Player pla1,Player pla2,int condition);  /*����condition�Ƚ�Player�������ݴ�С*/
 void reverse(Player pla[],int n);             /*��Ա��¼����Ԫ������*/
  

 void calcuTotal(Player pla[],int n);           /*����������Ա���ܵ÷�*/
 void calcuRank(Player pla[],int n);           /*�����ּܷ�����Ա�����Σ������в�������*/
 void sortPla(Player pla[],int n,int condition);   /*ѡ�񷨴�С�������򣬰�condition���涨������*/
  

 
 
 int searchPla(Player pla[],int n,Player s,int condition,int f[]) ;  /*������������������pla��ȵĸ�Ԫ��*/
                                                                     /*�±�����f�����У���f��������Ϊ���ҽ�����ܲ�ֹһ����¼*/
 int insertPla(Player pla[],int n,Player s);                   /*�������в���һ��Ԫ�ذ����º�������*/
 int deletePla(Player pla[],int n,Player s);                   /*��������ɾ��һ��ָ�����º����Ԫ��*/
 
 
 #endif