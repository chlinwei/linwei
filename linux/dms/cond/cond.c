// 通过条件变量解决生产者——消费者问题
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <pthread.h>
#define MAX_STOCK 10 // 仓库容量
char g_storage[MAX_STOCK]; // 仓库
size_t g_stock = 0; // 当前库存
pthread_mutex_t g_mutex =
	PTHREAD_MUTEX_INITIALIZER;
pthread_cond_t g_nofull = // 非满条件变量
	PTHREAD_COND_INITIALIZER;
pthread_cond_t g_noempty = // 非空条件变量
	PTHREAD_COND_INITIALIZER;
// 显示库存
void show (char const* who, char const* op,
	char prod) {
	printf ("%s：", who);
	size_t i;
	for (i = 0; i < g_stock; ++i)
		printf ("%c", g_storage[i]);
	printf ("%s%c\n", op, prod);
}
// 生产者线程
void* producer (void* arg) {
	char const* who = (char const*)arg;
	for (;;) {
		pthread_mutex_lock (&g_mutex);
		while (g_stock >= MAX_STOCK) {
			printf ("\033[;;32m%s：满仓！"
				"\033[0m\n", who);
			pthread_cond_wait (&g_nofull,
				&g_mutex);
		}
		char prod = 'A' + rand () % 26;
		show (who, "<-", prod);
		g_storage[g_stock++] = prod;
//		pthread_cond_signal (&g_noempty);
		pthread_cond_broadcast (&g_noempty);
		pthread_mutex_unlock (&g_mutex);
		usleep ((rand () % 100) * 1000);
	}
	return NULL;
}
// 消费者线程
void* customer (void* arg) {
	char const* who = (char const*)arg;
	for (;;) {
		pthread_mutex_lock (&g_mutex);
		while (! g_stock) {
			printf ("\033[;;31m%s：空仓！"
				"\033[0m\n", who);
			pthread_cond_wait (&g_noempty,
				&g_mutex);
		}
		char prod = g_storage[--g_stock];
		show (who, "->", prod);
//		pthread_cond_signal (&g_nofull);
		pthread_cond_broadcast (&g_nofull);
		pthread_mutex_unlock (&g_mutex);
		usleep ((rand () % 100) * 1000);
	}
	return NULL;
}
int main (void) {
	srand (time (NULL));
	pthread_t tid;
	pthread_create (&tid, NULL, producer,
		"生产者1");
	pthread_create (&tid, NULL, producer,
		"生产者2");
	pthread_create (&tid, NULL, producer,
		"生产者3");
	pthread_create (&tid, NULL, producer,
		"生产者4");
	pthread_create (&tid, NULL, customer,
		"消费者1");
	pthread_create (&tid, NULL, customer,
		"消费者2");
	pthread_create (&tid, NULL, customer,
		"消费者3");
	pthread_create (&tid, NULL, customer,
		"消费者4");
	getchar ();
	return 0;
}



