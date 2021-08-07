#define _CRT_SECURE_NO_WARNINGS   1

//C99 中，结构中的最后一个元素允许是未知大小的数组，这就叫做『柔性数组』成员
//结构中的柔性数组成员前面必须至少一个其他成员。
//sizeof 返回的这种结构大小不包括柔性数组的内存。
//包含柔性数组成员的结构用malloc()函数进行内存的动态分配，并且分配的内存应该大于结构的大小，以适应
//柔性数组的预期大小。

//柔性数组更有优势
//上述 代码1 和 代码2 可以完成同样的功能，但是 方法1 的实现有两个好处： 第一个好处是：方便内存释放
//如果我们的代码是在一个给别人用的函数中，你在里面做了二次内存分配，并把整个结构体返回给用户。用
//户调用free可以释放结构体，但是用户并不知道这个结构体内的成员也需要free，所以你不能指望用户来发
//现这个事。所以，如果我们把结构体的内存以及其成员要的内存一次性分配好了，并返回给用户一个结构体
//指针，用户做一次free就可以把所有的内存也给释放掉。
//第二个好处是：这样有利于访问速度.
//连续的内存有益于提高访问速度，也有益于减少内存碎片。（其实，我个人觉得也没多高了，反正你跑不了
//要用做偏移量的加法来寻址）





//#include<stdio.h>
//typedef struct st_type
//{
//	int i;
//	int a[0];//柔性数组成员
//}type_a;
//int main()
//{
//
//}


////在计算大小时候不包含柔性数组
//#include<stdio.h>
//#include<string.h>
//
//struct st
//{
//	int n;
//	char i;
//	char str[0];//柔性数组
//};
//
//int main()
//{
//	struct st st1;
//	printf("%d\n", sizeof(st1));
//	return 0;
//}

//#include<stdio.h>
//#include<stdlib.h>
//
//struct s
//{
//	int n;
//	int arr[];
//};
//
//int main()
//{
//	//struct s s1;不要这么创建柔性数组
//	struct s*ptr=(struct s*)malloc(sizeof(struct s) + 10 * sizeof(int));
//	ptr->n = 100;
//	int i = 0;
//	for (int i = 0; i < 10; i++)
//	{
//		ptr->arr[i] = i;
//	}
//	return 0;
//}


//这种方式不叫柔性数组
//#include<stdio.h>
//#include<stdlib.h>
//
//typedef struct s
//{
//	int n;
//	int *arr;
//}S;
//
//int main()
//{
//	S* ps=(S*)malloc(sizeof(S));
//	ps->arr =(int*) malloc(10 * sizeof(int));
//
//	return 0;
//}




