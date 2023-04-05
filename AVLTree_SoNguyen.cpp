#ifndef AVLTree_SoNguyen_CPP
#define AVLTree_SoNguyen_CPP
#include <AVLTree_SoNguyen.h>

AVLNode *createAVLNode(ItemType x)
{
    AVLNode *p = new AVLNode;
    if (p == NULL)
        printf("Not enough memory!");
        return NULL;
    p->BalFactor = 0;
    p->Info = x;
    p->Left = p->Right = NULL;
    return p;
}

void initAVLTree(AVLTree &avl)
{
    avl.Root = NULL;
}

void RotateLL(AVLNode *&T)
{
    AVLNode *T1 = T->Left;
    T->Left = T1->Right;
    switch (T1->BalFactor)
    {
    case LH:
        T->BalFactor = EH;
        T1->BalFactor = EH;
        break;
    
    case EH:
        T->BalFactor = LH;
        T1->BalFactor = LH;
        break;
    }
    T = T1;
}

void RotateLR(AVLNode *&T)
{
    AVLNode *T1 = T->Left;
    AVLNode *T2 =T1->Right;
    T1->Right = T2->Right;
    T2->Left = T1;
    T->Left = T2->Right;
    T2->Right = T;
    switch (T2->BalFactor)
    {
    case LH:
        T->BalFactor = RH;
        T1->BalFactor = EH;
        break;
    
    case EH:
        T->BalFactor = EH;
        T1->BalFactor = EH;
        break;
    case RH:
        T->BalFactor = EH;
        T1->BalFactor = LH;
        break;
    }
    T2->BalFactor = EH;
    T = T2;
}

void RotateRL(AVLNode *&T)
{
    AVLNode *T1 = T->Right;
    AVLNode *T2 = T1->Left;
    T1->Left = T2->Right;
    T->Right = T2->Left;
    T2->Left = T;
    switch (T2->BalFactor)
    {
    case RH:
        T->BalFactor = LH;
        T1->BalFactor = EH;
        break;
    
    case EH:
        T->BalFactor = EH;
        T1->BalFactor = EH;
        break;
    case LH:
        T->BalFactor = EH;
        T1->BalFactor = RH;
        break;
    }
    T2->BalFactor = EH;
    T = T2;
}
void RotateRR(AVLNode *&T)
{
    AVLNode *T1 = T->Right;
    T->Right = T1->Left;
    T1->Left = T;
    switch (T1->BalFactor)
    {
    case RH:
        T->BalFactor = EH;
        T1->BalFactor = EH;
        break;
    
    case EH:
        T->BalFactor = RH;
        T1->BalFactor = LH;
        break;
    }    
    T = T1;
}
int BalanceRight(AVLNode* &T)
{ //Khi cây T lệch bên phải cần cân bằng lại
    AVLNode* T1 = T->Right;
    switch(T1->BalFactor)
    {
    case LH:
        RotateRL(T);
        return 2;
    case EH:
        RotateRR(T);
        return 1;
    case RH:
        RotateRR(T);
        return 2;
    }
    return 0;
}

int InsertAVLNode(AVLNode* &T, AVLNode* p)
{
    if(p == NULL)
        return -1; //Nút mới p muốn thêm không tồn tại
    if(T == NULL)
    { //Cây rỗng nên thêm nút mới p vào gốc
        T = p;
        return 2; //Thực hiện thành công nút mới p
    }
    //Cây không rỗng
    int Result;
    if(T->Info == p->Info)
        return 0; //Không thêm được vì tồn tại nút có giá trị bằng x
    if(T->Info > p->Info)
    {
        Result = InsertAVLNode(T->Left, p);
        if(Result < 2)
            return Result;
        switch(T->BalFactor)
        {
        case RH:
            T->BalFactor = EH;
            return 1;
        case EH:
            T->BalFactor = LH;
            return 2;
        case LH:
            BalanceLeft(T);
            return 1;
        }
    }
    else
    {
        Result = InsertAVLNode(T->Right, p);
        if(Result < 2)
            return Result;
        switch(T->BalFactor)
        {
        case LH:
            T->BalFactor = EH;
            return 1;
        case EH:
            T->BalFactor = RH;
            return 2;
        case RH:
            BalanceRight(T);
        return 1;
        }
    }
}

int SearchStandFor(AVLNode* &p, AVLNode* &q)
{
    int Result;
    if(q->Left)
    {
        Result = SearchStandFor(p, q->Left);
        if(Result < 2)
            return Result;
        switch(q->BalFactor)
        {
        case LH:
            q->BalFactor = EH;
            return 2;
        case EH:
            q->BalFactor = RH;
            return 1;
        case RH:
            return BalanceRight(q);
        }
    }
    else
    {
        p->Info = q->Info;
        p = q;
        q = q->Right;
    }
    return 2;
}

int DeleteAVLNode(AVLNode* &T, ItemType x)
{ //Xóa nút có Info bằng với x
    int Result;
    if(T == NULL)
        return 0; //Không thực hiện được
    if(T->Info > x)
    {
        Result = DeleteAVLNode(T->Left, x);
        if(Result < 2)
            return Result;
            switch(T->BalFactor)
            {
            case LH:
                T->BalFactor = EH;
                return 2;
            case EH:
                T->BalFactor = RH;
                return 1;
            case RH:
                return BalanceRight(T);
            }
    }
    else if(T->Info < x)
    {
        Result = DeleteAVLNode(T->Right, x);
        if(Result < 2)
            return Result;
        switch(T->BalFactor)
        {
        case RH:
            T->BalFactor = EH;
            return 2;
        case EH:
            T->BalFactor = LH;
            return 1;
        case LH:
            return BalanceLeft(T);
        }
    }
    else
    {
        AVLNode* p = T;
        if(T->Left == NULL)
        {
            T = T->Right;
            Result = 2;
        }
        else
        {
            if(T->Right == NULL)
            {
                T = T->Left;
                Result = 2;
            }
            else
            {
                Result = SearchStandFor(p, T->Right);
                if(Result < 2)
                    return Result;
                switch(T->BalFactor)
                {
                case RH:
                    T->BalFactor = EH;
                    return 2;
                case EH:
                    T->BalFactor = LH;
                    return 1;
                case LH:
                    return BalanceLeft(T);
                }
            }
        }
        delete p;
        return Result;
    }
    return Result;
}

AVLNode* FindAVLNode(AVLNode* root, ItemType x)
{
    if(!root) return NULL;
    if(root->Info == x) return root;
    else if(root->Info > x)
        return FindAVLNode(root->Left, x);
    else
        return FindAVLNode(root->Right, x);
}

int DeleteAVLTree(AVLNode *&root)
{ //Ham xoa toan bo cay
    if(!root) return 0;
    DeleteAVLTree(root->Left); //Xóa con trái
    DeleteAVLTree(root->Right); //Xóa con phải
    delete root;
    return 1;
}

void LNR(AVLNode* root)
{ //Ham duyet cay theo thu tu LNR
    if(!root) return;
    LNR(root->Left); //Duyệt sang nhánh trái
    printf("%4d", root->Info); //Show nội dung nút gốc
    LNR(root->Right); //Duyệt sang nhánh phải
}

void CreateAVLTreeFromArray(AVLTree &avl, ItemType a[], int n)
{ //Ham tao cay NPTK tu mang a
    initAVLTree(avl);
    for(int i = 0; i < n; i++)
    {
        AVLNode* p = createAVLNode(a[i]);
        InsertAVLNode(avl.Root, p);
    }
}
#endif