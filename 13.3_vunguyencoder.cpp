/*******************************************************************************
************ Bài tập lập trình C++ cơ bản - Bài 10.3 ****************************
********************** vunguyencoder.com **************************************
1. In ra tên người ko thích một ai.
2. In ra người đang yêu đơn phương.
Người đơn phương là người đi thích người khác mà ko có chiều ngược lại
3. In ra tên của các cặp đôi khác giới yêu nhau
Hai người yêu nhau là 2 người đều thích đối phương.
4. In ra tên người đa tình - là người được 2 người thích trở lên
* ******************************************************************************/

#include <iostream>
#include <string>

using namespace std;

struct Person
{
    Person(string ht, int gt)
    {
        ho_ten = ht;
        gioi_tinh = gt;
        crush = NULL;
    }

    string ho_ten;
    int gioi_tinh; // 1: Nam / -1: Nu
    Person* crush;
};

int main()
{
    const int MAX = 9;

    // Tạo mảng thông tin 
    Person *list[MAX];
    list[0] = new Person("Nguyen Anh Vu", 1);
    list[1] = new Person("Truong Anh Tuan", 1);
    list[2] = new Person("Pham Dinh Hung", 1);
    list[3] = new Person("Bach Van Thang", -1);
    list[4] = new Person("Tran Mai Anh", -1);
    list[5] = new Person("Eimi Fukada", -1);
    list[6] = new Person("Khac Tiep", 1);
    list[7] = new Person("Ngoc Trinh", -1);
    list[8] = new Person("Midu", -1);

    // Tạo mối quan hệ tình cảm 
    list[0]->crush = list[5];
    list[1]->crush = list[5];
    list[2]->crush = list[4];
    list[3]->crush = list[7];
    list[4]->crush = list[2];
    list[5]->crush = NULL;
    list[6]->crush = list[7];
    list[7]->crush = NULL;
    list[8]->crush = NULL;
    // 0,1 = 5; 2 = 4; 3 = 7; 4 = 2; 5 = NULL; 6 = 7; 7 = NULL; 8 = NULL
    {
        cout << "Ket qua 1:";
        // Noi dung can hoan thanh
        for(int i = 0; i < MAX; i++){
            if(list[i]->crush == NULL){
                cout << list[i]->ho_ten << "; ";
            }
        }
        cout << "\n";
    }
    
    {
        cout << "Ket qua 2:\n";
        // Noi dung can hoan thanh
        for(int i = 0; i < MAX; i++){
            if(list[i]->crush != NULL  && list[i]->crush->crush != list[i]){
                cout << "\t" << "(" << list[i]->ho_ten << " --> " << list[i]->crush->ho_ten << ")\n";
            }
        }
    }

    {
        cout << "Ket qua 3:\n";
        // Noi dung can hoan thanh
        for(int i = 0; i < MAX; i++){
            if(((list[i]->crush != NULL && list[i]->gioi_tinh > 0) && (list[i]->crush->crush == list[i] && list[i]->crush->gioi_tinh < 0))){
                cout << "\t(" << list[i]->ho_ten << " <--> " << list[i]->crush->ho_ten << ")" << endl;
            }
        }
    }
    
    {
        cout << "Ket qua 4: ";
        // Noi dung can hoan thanh
        for(int i = 0; i < MAX; i++){
            int count = 0;
            for(int j = 0; j < MAX; j++){
                if(list[j]->crush == list[i]){
                    count++;
                }
            }
            if(count >= 2){
                cout << list[i]->ho_ten << "; ";
            }
        }
    }
}




