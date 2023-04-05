# include <AVLTree_SoNguyen.h>
//===================================================================
void ShowMenu()
{
printf("\n************************************************");
printf("\n* MENU *");
printf("\n*----------------------------------------------*");
printf("\n* 1. Khoi tao cay nhi phan tim kiem can bang *");
printf("\n* 2. Duyet LNR *");
printf("\n* 3. Them nut co gia tri bat ky vao cay *");
printf("\n* 4. Xoa nut co gia tri bat ky vao cay *");
printf("\n* 5. Tim kiem nut co gia tri x tren cay *");
printf("\n* 6. Xoa cay *");
printf("\n* 0. Thoat chuong trinh *");
printf("\n************************************************");
}
//===================================================================
void main()
{
    int SelectFunction, kq, high;
    AVLTree avl;
    AVLNode* p;
    ItemType x;
    ItemType a[]={10, 8, 9, 5, 4, 17, 15, 16, 20, 11, 12, 13, 19, 7, 25, 6};
    int n = 16;
    initAVLTree(avl);
    do
    {
        ShowMenu();
        printf("\nHay chon mot chuc nang cua chuong trinh: ");
        scanf("%d", &SelectFunction);
        switch(SelectFunction)
        {
        case 1:
            CreateAVLTreeFromArray(avl, a, n);
            break;
        case 2:
            printf("\nNoi dung cua cay voi phep duyet LNR: ");
            LNR(avl.Root);
            break;
        case 3:
            printf("Nhap gia tri bay ky cho nut muon them: ");
            scanf("%d", &x);
            p = createAVLNode(x);
            kq = InsertAVLNode(avl.Root, p);
            if(kq <= 0)
            printf("\nKhong the them duoc nut co gia tri %d", x);
            else
            {
                printf("\nNoi dung cua cay sau khi them nut %d la: ", x);
                LNR(avl.Root);
            }
            break;
        case 4:
            printf("Nhap gia tri bay ky cho nut muon them: ");
            scanf("%d", &x);
            kq = DeleteAVLNode(avl.Root, x);
            if(kq == 0)
                printf("\nKhong the xoa duoc nut co gia tri %d", x);
            else
            {
                if(avl.Root == NULL)
                    printf("\nCay rong!");
                else
                {
                    printf("\nNoi dung cua cay sau khi xoa nut %d la: ", x);
                    LNR(avl.Root);
                }
            }
            break;
        case 5:
            printf("Nhap gia tri bay ky cho nut muon them: ");
            scanf("%d", &x);
            p = FindAVLNode(avl.Root, x);
            if(p == NULL)
                printf("\nKhong tim thay nut co gia tri %d", x);
            else
                printf("\nCo nut co gia tri %d tren cay", x);
            break;
        case 6:
            kq = DeleteAVLTree(avl.Root);
            if(kq == 0)
                printf("\nKhong the xoa cay");
            else
                printf("\nDa xoa toan bo cay");
            break;
        }      
    }while(SelectFunction != 0);
}