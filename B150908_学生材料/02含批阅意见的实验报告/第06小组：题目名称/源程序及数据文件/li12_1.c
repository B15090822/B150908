/*li12_1.c*/
#include<stdio.h>
#include<stdlib.h>
#include"file.h"
#include"player.h"

void printHead( )      /*打印球员信息的表头*/
{
printf("%3d%8s%2d%2d%2d%2%2d%2d\n","球员号码","姓名","得分","助攻","篮板","抢断","失误","名次");
}

void menu( )         /*顶层菜单函数*/
{
		printf("******** 1. 显示基本信息 ********\n");
		printf("******** 2. 基本信息管理 ********\n");
		printf("******** 3. 球员数据管理 ********\n");
		printf("******** 4. 比赛得分统计 ********\n");
     printf("******** 5. 根据条件查询 ********\n");
		printf("******** 0. 退出         ********\n");
}

void menuBase( )     /*2、基本信息管理菜单函数*/
{
		printf("%%%%%%%% 1. 插入球员记录 %%%%%%%%\n");
		printf("%%%%%%%% 2. 删除球员记录 %%%%%%%%\n");
		printf("%%%%%%%% 3. 修改球员记录 %%%%%%%%\n");
		printf("%%%%%%%% 0. 返回上层菜单 %%%%%%%%\n");
}

void menuScore( )     /*3、球员数据管理菜单函数*/
{
		printf("@@@@@@@@ 1. 计算球员总得分 @@@@@@@@\n");
		printf("@@@@@@@@ 2. 根据总得分排名 @@@@@@@@\n");
		printf("@@@@@@@@ 0. 返回上层菜单 @@@@@@@@\n");
}
 
void menuCount( )    /*4、比赛得分统计菜单函数*/
{
		printf("&&&&&&&& 1. 求总得分最高分 &&&&&&&&\n");
		printf("&&&&&&&& 2. 求总得分最低分 &&&&&&&&\n");
		printf("&&&&&&&& 0. 返回上层菜单 &&&&&&&&\n");
}

void menuSearch()    /*5、根据条件查询菜单函数*/
{
		printf("######## 1. 按姓名查询   ########\n");
		printf("######## 2. 按球衣号码查询   ########\n");
		printf("######## 0. 返回上层菜单 ########\n");
}

int baseManage(Player pla[],int n)    	     /*该函数完成基本信息管理*/
/*按学号进行插入删除修改，球衣号码不能重复*/
{  
		int choice,t,find[NUM];
     Player s;
do
	    {   
menuBase( );                  /*显示对应的二级菜单*/
printf("choose one operation you want to do:\n");
		     scanf("%d",&choice);	          /*读入选项*/
		     switch(choice)
		     {
			   case 1:	 readPla(&s,1);       /*读入一条待插入的球员记录*/
					 n=insertPla(pla,n,s);   /*调用函数插入球员记录*/
					 break;
			   case 2:  printf("Input the number deleted\n");
					 scanf("%ld",&s.num);  /*读入一个待删除的球员球衣号码*/
					 n=deletePla(stu,n,s);   /*调用函数删除指定球衣号码的球员记录*/
					 break;
			   case 3:  printf("Input the number modified\n");
					 scanf("%ld",&s.num);  /*读入一个待修改的球员球衣号码*/
				      t=searchPla(pla,n,s,1,find) ; /*调用函数查找指定球衣号码的球员记录*/
				      if (t)                 /*如果该球衣号码的记录存在*/
					 {
						  readPla(&s,1);   /*读入一条完整的球员记录信息*/
					      stu[find[0]]=s;    /*将刚读入的记录赋值给需要修改的数组记录*/ 					 
					  }					 
					 else                 /*如果该球衣号码的记录不存在*/ 
 printf("this player is not in,can not be modified.\n"); /*输出提示信息*/
					 break;
			    case 0: break;
		    }
	}while(choice);
return n;                             /*返回当前操作结束后的实际记录条数*/
}

void scoreManage(Player pla[],int n)          /*该函数完成球员数据管理功能*/
{  
	int choice;
	do
	{
		menuScore( );                        /*显示对应的二级菜单*/
		printf("choose one operation you want to do:\n");
		scanf("%2d",&choice);	                 /*读入二级选项*/
		switch(choice)
		{
			case 1:   calcuTotal(stu,n);         /*求所有球员的总得分*/
					  break;
			case 2:   calcuRank(stu,n);         /*根据所有球员的总得分排名次*/
				      break;		
			case 0:   break;
		}
	}while(choice);
}

void printMarkCourse(char *s,double m[5][2],int k)   /*打印分数通用函数，被countManage 调用*/
{                 /*形式参数k代表输出不同的内容，0、1分别对应最高分、最低分*/
int i;
    printf(s);                                  /*这里的s传入的是输出分数的提示信息*/
    for (i=0;i<5;i++)                           /*i控制哪一场比赛*/
		  printf("%10.2lf",m[i][k]);
	   printf("\n");
}

void countManage(Player pla[],int n)               /*该函数完成比赛数据统计功能*/
{
		int choice;
		double mark[5][2];
		do
		{
			menuCount( );                        /*显示对应的二级菜单*/
			calcuMark(mark,pla,n);                 /*调用此函数求五场比赛的最高、最低分*/
			printf("choose one operation you want to do:\n");
			scanf("%d",&choice);
			switch(choice)
			{
				case 1:   printMarkCourse("五场比赛的最高分分别是:\n",mark,0);  /*输出最高分*/
				      break;
				case 2:   printMarkCourse("五场比赛的最低分分别是:\n",mark,1);  /*输出最低分*/
				      break;
				case 0:   break;
			}
		}while (choice);
}

void searchManage(Player pla[],int n)               /*该函数完成根据条件查询功能*/
{
    int i,choice,findnum,f[NUM];
Student s;
	   do
{
			menuSearch( );                         /*显示对应的二级菜单*/
			printf("choose one operation you want to do:\n");
			scanf("%d",&choice);
			switch(choice)
			{
				case 1:   printf("Input a player\'s num will be searched:\n");
				      scanf("%2d",&s.num);         /*输入待查询球员的球衣号码*/
					  break;
				case 2:   printf("Input a player\'s name will be searched:\n");
				      scanf("%8s",s.name);	          /*输入待查询球员的姓名*/		  
				      break;   
				case 3:   printf("Input a rank will be searched:\n");
				      scanf("%2d",&s.rank);          /*输入待查询球员的名次*/
					  break;
				case 0:   break;
			}
		 	if (choice>=1&&choice<=2)
			{ 
				findnum=searchPla(pla,n,s,choice,f);    /*查找的符合条件元素的下标存于f数组中*/
				if (findnum)				     /*如果查找成功*/
				{
			   		 printHead( );                  /*打印表头*/
					 for (i=0;i<findnum;i++)         /*循环控制f数组的下标*/
	      	 printPla(&pla[f[i]],1);      /*每次输出一条记录*/
				}
		    		else
			    	    printf("this record does not exist!\n"); /*如果查找不到元素，则输出提示信息*/
		     }		
	    }while (choice);
}

int runMain(Player pla[],int n,int choice)    /*主控模块，对应于一级菜单其下各功能选择执行*/
{
		switch(choice)
		{
			case 1: printHead( );           /* 1. 显示基本信息*/
				 sortPla(pla,n,1);         /*按球衣号码由小到大的顺序排序记录*/ 
          	 printStu(pla,n);          /*按球衣号码由小到大的顺序输出所有记录*/
					break;
			case 2: n=baseManage(pla,n);    /* 2. 基本信息管理*/
			   	     break;
			case 3: scoreManage(pla,n);     /* 3. 球员数据管理*/
					break;
			case 4: countManage(pla,n);     /* 4. 比赛得分统计*/
					break;
			case 5: searchManage(pla,n);     /* 5. 根据条件查询*/
				     break;
          case 0: break;
		}
		return n;
}

int main( )
{
		Player pla[NUM];                /*定义实参一维数组存储球员记录*/
      int choice,n;
	 n=readFile(pla);                  /*首先读取文件，记录条数返回赋值给n*/
	 if (!n)                          /*如果原来的文件为空*/
	     {
		    n=createFile(pla);              /*则首先要建立文件，从键盘上读入一系列记录存于文件*/
}	 	 
	do
	     {
	         menu();                      /*显示主菜单*/
	         printf("Please input your choice: ");
	         scanf("%d",&choice);
	         if (choice>=0&&choice<=5)
	              n=runMain(pla,n,choice);    /*通过调用此函数进行一级功能项的选择执行*/
	         else 
		          printf("error input,please input your choice again!\n");
	} while (choice);
	sortPla(pla,n,1);                   /*存入文件前按球衣号码由小到大排序*/ 
	     saveFile(pla,n);                   /*将结果存入文件*/
      return 0;
}
