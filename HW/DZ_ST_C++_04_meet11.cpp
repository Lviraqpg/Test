#include <iostream>
#include <vector>

// //двоичного поиска в массиве,
// замены элемента массива на переданное значение
template<typename T>

class VectorOperations{
public:
    T findMax(std::vector<T>& vec){
        T max=vec[0];
        for(int i=1; i<vec.size();i++ ){
            if(max<vec[i]){
                max=vec[i];
            }
        }
        std::cout<<"Max is:"<< max<<std::endl;
    }

    T findMin(std::vector<T>& vec){
        T min=vec[0];
        for(int i=1; i<vec.size();i++ ){
            if(min>vec[i]){
                min=vec[i];
            }
        }
        std::cout<<"Min is:"<<min<<std::endl;
    }

    void sortVector(std::vector<T>&vec){
        T key;
        int j;
        for (int i=1;i<vec.size(); i++){
            key=vec[i];
            j=i-1;
            while(j>=0 && vec[j]>key){
                vec[j+1]=vec[j];
                j-=1;
            }
            vec[j+1]=key;
        }
    }

    void elemReplace(std::vector<T>& vec){
        T newElem = vec[0];
        std::cout<<"Please, enter new element:"<<" ";
        std::cin>>newElem;
        T repElem=vec[0];
        std::cout<<"Please, enter elem to replace:"<<"  ";
        std::cin>>repElem;
        for(int i=0; i<vec.size();i++){
            if (repElem==vec[i]){
                vec[i]=newElem;
            }
        }
    }
    void binarySearch(std::vector<T>& vec) {
        T key;
        std::cout << "Please, enter the key element:" << " ";
        std::cin >> key;
        bool flag = false;
        T l = vec[0];
        T r = vec.size()-1;
        T mid;

        while ((l <= r) && (flag != true)) {
            mid = (l + r) / 2;
            if (vec[mid] == key)
                flag = true;
            if (vec[mid] > key)
                r = mid - 1;
            else
                l = mid + 1;
        }
        if (flag)
            std::cout << "Elemets' index is:" << mid << "in vector";
        else
            std::cout << "Can's find the element" << std::endl;
    }


    void printVector(std::vector<T>& vec){
        for(int i=0; i<vec.size();i++){
            std::cout<<vec[i]<<" ";
        }
        std::cout<<std::endl;
    }
};


int main() {
    std::vector<int> g{1,2,3,4,5,6,7,8};
    std::vector<double>g1{1.2,3.4,3.5,6.7,7.4,9.0,0.0};
    VectorOperations<int> vo;
    vo.printVector(g);
    vo.findMax(g);
    vo.findMin(g);
    VectorOperations<double> vo1;
    vo1.findMax(g1);
    vo1.findMin(g1);
    vo1.sortVector(g1);
    vo1.printVector(g1);
    vo.elemReplace(g);
    vo.printVector(g);
    vo1.sortVector(g1);
    vo1.printVector(g1);
    vo1.binarySearch(g1);
}