#include"List.h"
int main(int argc, char* argv[])
{
	List mylist;
	ListInit(&mylist);
	ElemType item, key;
	ListNode* p = NULL;
	int pos;
	int select = 1;
	while (select)
	{
		printf("********************************************\n");
		printf("* [1] push_back           [2] push_front   *\n");
		printf("* [3] show_list           [0] quit_system  *\n");
		printf("* [4] pop_back            [5] pop_front    *\n");
		printf("* [*6] insert_pos         [7] insert_val   *\n");
		printf("* [*8] erase_pos          [9] erase_val    *\n");
		printf("* [*10] find_pos          [11] find_val    *\n");
		printf("* [12] sort               [13] reverse     *\n");
		printf("* [14] length            [*15] capacity    *\n");
		printf("* [16] clear              [17] destroy     *\n");
		printf("********************************************\n");
		printf("��ѡ��>");
		scanf("%d", &select);
		if (select == 0)
			break;
		switch (select)
		{
		case 1:
			printf("������Ҫ�������<��-1����>��>");
			while (scanf("%d", &item), item != -1)
			{
				ListPushBack(&mylist, item);
			}
			break;
		case 2:
			printf("������Ҫ�������<��-1����>��>");
			while (scanf("%d", &item), item != -1)
			{
				ListPushFront(&mylist, item);
			}
			break;
		case 3:
			ListShow(mylist);
			break;
		case 4:
			ListPopBack(&mylist);
			break;
		case 5:
			ListPopFront(&mylist);
			break;
		case 6:
			break;
		case 7:
			printf("������Ҫ�����ֵ:>");
			scanf("%d", &item);
			ListInsertByVal(&mylist, item);
			break;
		case 8:
			break;
		case 9:
			printf("������Ҫɾ����ֵ:>");
			scanf("%d", &item);
			ListEraseByVal(&mylist, item);
			break;
		case 10:
			//printf("������Ҫ���ҵ�λ��:>");
			//scanf("%d", &pos);
			//int ret = SeqListFindByPos(&mylist, pos);
			//printf("%d\n", ret);
		case 11:
			printf("������Ҫ���ҵ�ֵ:>");
			scanf("%d", &key);
			 p = ListFindByVal(mylist, key);
			if (p ==NULL)
				printf("Ҫ���ҵ�%d���ݲ�����.\n", key);
			else
				printf("%dλ�õ������ѱ����ҵ�.\n", key);
			break;
		case 12:
			ListSort(&mylist);
			printf("�Ѱ���������\n");
			break;
		case 13:
			ListReverse(&mylist);
			break;
		case 14:
			printf("������ĳ���Ϊ:> %d\n", ListLength(mylist));
			break;
		case 15:
			//ListCapacity(&mylist);
		case 16:
			ListClear(&mylist);
		case 17:
			ListDestroy(&mylist);
		default:
			break;
		}
	}
	return 0;
}