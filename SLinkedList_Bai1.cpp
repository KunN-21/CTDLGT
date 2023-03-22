#include <conio.h>
#include <stdio.h>
#include <time.h>
#include <random>

typedef int ItemType;
                    //Cau Truc && Khoi Tao
//============================================================//
struct SNode
{
    ItemType Info;
    SNode* Next;
};
struct SLinkedList
{
    SNode* Head;
    SNode* Tail;
};

SNode* createSNode(ItemType x)
{
    SNode *p = new SNode;
    p->Info=x;
    p->Next=NULL;
    return p;
}
void initSLinkedList(SLinkedList &sl)
{
    sl.Head = sl.Tail = NULL;
}
//============================================================//

int isEmpty(SLinkedList sl)
{
    return (sl.Head==0)? 1:0;
}

int insertHead(SLinkedList &sl, SNode *p)
{
    if(p==NULL) return 0;
    if(isEmpty(sl)==1)
    {
        sl.Head=p;
        sl.Tail=p;
        return 1;
    }
    p->Next=sl.Head;
    sl.Head=p;
    return 1;
}

int insertTail(SLinkedList &sl, SNode *p)
{
    if(p==NULL) return 0;
    if(isEmpty(sl)==1)
    {
        sl.Head=p;
        sl.Tail=p;
        return 1;
    }
    sl.Tail->Next=p;
    sl.Tail=p;
    return 1;
}

int deleteHead(SLinkedList &sl)
{
    if(isEmpty(sl)==1) return 0;
    if(sl.Head == sl.Tail)
    {
        delete sl.Head;
        sl.Head = sl.Tail = NULL;
        return 1;
    }
    SNode *q = sl.Head->Next; // q la SNode next cua Head
    delete sl.Head;
    sl.Head=q;
    return 1;
}

int deleteTail(SLinkedList &sl)
{
    if(isEmpty(sl)==1) return 0;
    if(sl.Head == sl.Tail)
    {
        delete sl.Tail;
        sl.Head = sl.Tail = NULL;
        return 1;
    }
    SNode *q = sl.Head;
    for(q; q->Next != sl.Tail; q = q->Next){} // q la SNode trc Tail
    q->Next=NULL;
    delete sl.Tail;
    sl.Tail=q;
    return 1;
}

void autoCreateSList(SLinkedList &sl)
{
    int n, kq;
    do
    {
        printf("\nNhap so pt muon them vao SList: "); scanf("%d", &n);
    }while(n<=0);
    srand((unsigned)time(NULL));
    for(int i = 1; i <= n; i++)
    {
        ItemType x = (rand()%199)-99;   //Tạo 1 số trong đoạn [-99, 99]
        SNode* p = createSNode(x);
        kq = insertHead(sl,p);
        if(kq==0) printf("\nKhong them duoc nut %d", x);
    }
}

void Show(SLinkedList sl)
{
    printf("Pt trong SList la: ");
    SNode *temp = sl.Head;
    for(temp; temp != NULL; temp = temp->Next)
    {
        printf("%d ",temp->Info);
    }
}

SNode* Search(SLinkedList sl, ItemType x)
{
    
    SNode* q = sl.Head;
    for(q; q != NULL; q = q->Next)
    {
        if(q->Info == x) return q;
    }
    return NULL;
}

int insertFront(SLinkedList &sl, ItemType &x, ItemType &y)
{
    printf("\nNhap x = "); scanf("%d",&x);
    printf("Nhap y = "); scanf("%d",&y);
    if(isEmpty(sl) == 1) return 0;
    SNode* p = createSNode(x); if(p == NULL) return 0;
    if(sl.Head->Info == y)
    {
        insertHead(sl, p);
        return 1;
    }
    SNode* front= sl.Head;
    for(front; front->Next != NULL; front = front->Next)
    {

        if(front->Next->Info == y)
        {
            p->Next=front->Next;
            front->Next=p;
            return 1;
        }
    }
    return 0;
}

int insertBehind(SLinkedList &sl, ItemType &x, ItemType &y)
{
    printf("\nNhap x = "); scanf("%d",&x);
    printf("Nhap y = "); scanf("%d",&y);
    if(isEmpty(sl) == 1) return 0;
    SNode* p = createSNode(x); if(p == NULL) return 0;
    if(sl.Tail->Info == y)
    {
        insertTail(sl, p);
        return 1;
    }
    SNode* behind = Search(sl, y); if(behind == NULL) return 0;
    p->Next = behind->Next;
    behind->Next = p;
    return 1;
}

void ShowMenu();
void Process();
int main()
{
    Process();
    return 0;
}

void ShowMenu()
{
printf("\n**********************************************");
printf("\n* MENU *");
printf("\n*--------------------------------------------*");
printf("\n* 1. Tao nut moi va xuat ra noi dung *");
printf("\n* 2. Tao danh sach bang tay (nhap lieu) *");
printf("\n* 3. Tao danh sach tu dong (ngau nhieu) *");
printf("\n* 4. Xuat noi dung danh sach *");
printf("\n* 5. Them nut vao dau danh sach *");
printf("\n* 6. Them nut vao cuoi danh sach *");
printf("\n* 7. Them nut p chua x vao sau nut q chua y *");
printf("\n* 8. Tim mot nut chua gia tri x bat ky *");
printf("\n* 0. Thoat chuong trinh *");
printf("\n**********************************************");
}

void Process()
{
    ItemType X, Y;
    SNode *P, *Q;
    int SelectFunction, kq;
    SLinkedList SL;
    initSLinkedList(SL);
    do
    {
        ShowMenu();
        do
        {
            printf("\nBan hay chon mot chuc nang (0 - 8): ");
            scanf("%d", &SelectFunction);
        }while(SelectFunction < 0 || SelectFunction > 8);
        switch(SelectFunction)
        {
            case 1:
                printf("\nNhap mot so nguyen bat ky: ");
                scanf("%d", &X);
                P = createSNode(X);
                printf("\nNoi dung nut moi vua tao la: ");
                printf("%d", P->Info);
                break;
            case 2:
                break;
            case 3:
                initSLinkedList(SL);
                autoCreateSList(SL);
                Show(SL);
                break;
            case 4:
                Show(SL);
                break;
            case 5:
                printf("\nCho biet gia tri nut muon them dau danh sach: ");
                scanf("%d", &X);
                P = createSNode(X);
                kq = insertHead(SL, P);
                if(kq == 0)
                    printf("\nKhong thuc hien duoc viec them dau danh sach");
                else
                    Show(SL);
                break;
            case 6:
            printf("\nCho biet gia tri nut muon them cuoi danh sach: ");
                scanf("%d", &X);
                P = createSNode(X);
                kq = insertTail(SL, P);
                if(kq == 0)
                    printf("\nKhong thuc hien duoc viec them cuoi danh sach");
                else
                    Show(SL);
            case 7:
                printf("\nNhap mot so nguyen x bat ky muon them: ");
                scanf("%d", &X);
                printf("\nNhap mot gia tri nut ke truoc: ");
                scanf("%d", &Y);
                int Q,P;
                kq = insertBehind(SL, Q, P);
                if(kq == 0)
                    printf("\nKhong thuc hien duoc viec them %d sau %d", X, Y);
                else
                    Show(SL);
                break;
            case 8:
                printf("\nNhap mot so nguyen x bat ky muon tim: ");
                scanf("%d", &X);
                SNode* m = Search(SL, X);
                if(m == NULL)
                    printf("\nKhong tim thay nut nao co gia tri bang %d", X);
                else
                    printf("\nTon tai nut co gia tri bang %d", X);
                break;
        }
    }while(SelectFunction != 0);
}