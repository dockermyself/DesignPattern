//
// Created by feng on 2020/11/19.
//

#ifndef DESIGNPATTERN_VISITOR_H
#define DESIGNPATTERN_VISITOR_H
#include <iostream>
//visitor + 可变模板
namespace visitor{
    constexpr int SIZE = 100;
    using v_ref = int (&)[SIZE];
    using v_ptr = int (*)[SIZE];
    class Interface{
    protected:
        v_ref _data;
    public:
        explicit Interface(v_ref data):_data(data){}
        virtual void op(v_ref data) = 0;
    };

    class Add : public Interface{
    public:
        explicit Add(v_ref data) : Interface(data) {}
        void op(v_ref data) override{
            for(std::size_t i = 0;i < SIZE;++i){
                data[i] += _data[i];
            }
        }
    };

    class Mul : public Interface{
    public:
        explicit Mul(v_ref data) : Interface(data) {}
        void op(v_ref data) override{
            for(std::size_t i = 0;i < SIZE;++i){
                data[i] *= _data[i];
            }
        }
    };

    class Sub : public Interface{
    public:
        explicit Sub(v_ref data) : Interface(data) {}
        void op(v_ref data) override{
            for(std::size_t i = 0;i < SIZE;++i){
                data[i] -= _data[i];
            }
        }
    };
    class Array{
        v_ref _data;
    public:
        explicit Array(v_ref data):_data(data){}
        template <typename V,typename... Args>
        void accept(V&& v,Args&&... args){
            v.op(_data);
            accept(args...);
        }
        void printArray(){
            for(size_t i = 0;i < SIZE; ++ i){
                if(i%10 == 9){
                    std::cout << _data[i] << "]" << std::endl;
                }
                else if(i%10 == 0){
                    std::cout  << "[" << _data[i] << ",";
                }
                else{
                    std::cout << _data[i] << ",";
                }
            }
        }
        virtual ~Array() = default;

    private:
        void accept(){}
    };
    void setArray(int (&data)[SIZE],int val) {
        for (int &i : data) {
            i = val;
        }
    }
    void testVisitor(){
        int data_1[SIZE] = {0};
        int data_2[SIZE] = {0};
        int data_3[SIZE] = {0};
        int data_4[SIZE] = {0};
        setArray(data_1,1);
        setArray(data_2,3);
        setArray(data_3,5);
        setArray(data_4,7);


        Array arr(data_1);
        Add add(data_2);
        Mul mul(data_3);
        Sub sub(data_4);
        arr.accept(add,mul,sub,sub,add,sub,mul);
        arr.printArray();

    }

}


#endif //DESIGNPATTERN_VISITOR_H
