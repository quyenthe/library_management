#include <bits/stdc++.h>
#include <vector>
#include <iostream>
using namespace std;
class library{
    protected:
        string book_title;
        int id_book;
    public:
        
        void set_title(string book_title)
        {
            this->book_title=book_title;
        }
        void set_idbook(int id_book)
        {
            this->id_book-id_book;
        }
        string get_title()
        {
            return book_title;
        }
        int get_id()
        {
            return id_book;
        }
        friend istream & operator >> (istream &,library &);
        friend ostream & operator << (ostream &, library);
        

};
istream & operator >> (istream & in, library &a)
{
    cin.ignore();
    cout<<"nhap ten sach:";
    getline(in,a.book_title);
    cout<<"nhap ma sach:";
    in>>a.id_book;
    in.ignore();
    return in;
}
ostream & operator << (ostream & out , library a)
{
    out<<"ten sach : "<<a.book_title<<endl;
    out<<"ma sach : "<<a.id_book<<endl;
    return out;
}

class SinhVien:public library{
    private:
        string name,birth,Class;
        int id;
    public:
        friend ostream & operator << (ostream & , SinhVien);
        friend istream & operator >> (istream & , SinhVien&);


};
istream & operator >> (istream & in, SinhVien &a )
{
    cout<<"nhap ten sv : ";
    in.ignore();
    getline(in,a.name);
   
    cout<<"nhap ngay sinh : ";
    getline(in,a.birth);
    
    cout<<"nhap ten lop : ";
    getline(in,a.Class);
    cout<<"nhap ma sv : ";
    in>>a.id;
    in.ignore();
    cout<<"nhap ten sach :";
    getline(in,a.book_title);
    cout<<"nhap id sach :";
    in>>a.id_book;
    return in;
}
ostream & operator << (ostream &out , SinhVien a){
    out<<"ten sv :"<<a.name<<endl;
    out<<"ngay sinh : "<<a.birth<<endl;
    out<<"lop :"<<a.Class<<endl;
    out<<"ma sv"<<a.id<<endl;
    out<<"ten sach muon :"<<a.book_title<<endl;
    out<<"id sach muon :"<<a.id_book<<endl;
    return out;

}
void add_book(library &a,vector<library > &b)
{
    cin>>a;  
    b.push_back(a);
}
void delete_book(vector<library > &b)
{
    string book;
    cin.ignore();
    cout<<"nhap ten sach can xoa :";
    getline(cin,book);
    int id;
    cout<<"nhap ten id sach can xoa:";
    cin>>id;
    for(int i=0;i<b.size();i++)
    {
        if(b[i].get_title()==book && b[i].get_id()==id)
        { 
            b[i]=b[b.size()-1];
            break;
        }

    }
    b.pop_back();
}
void search_book(vector<library> &b)
{
    string book;
    cin.ignore();
    cout<<"nhap ten sach can tim :";
    getline(cin,book);
    int id;
    cout<<"nhap ten id sach can tim:";
    cin>>id;
    
    for(int i=0;i<b.size();i++)
    {
        if(b[i].get_title()==book && b[i].get_id()==id)
        {
                cout<<b[i];
        }
        break;
    }
}
void list_book(vector<library>&b)
{
    for(int i=0;i<b.size();i++)
    {
        cout<<b[i];
    }
}
void muon_sach(SinhVien &a,vector<SinhVien> &b,vector<library>&c)
{
    cin>>a;
    b.push_back(a);
    for(int i=0;i<c.size();i++)
    {
        if(a.get_id()== c[i].get_id() && a.get_title()==c[i].get_title())
        {
            c[i]=c[c.size()-1];
            c.pop_back();
        }
    }
    
}
void tra_sach(library &a,vector<SinhVien>&b,vector <library> &c)
{
    cin>>a;
    for(int i=0;i<b.size();i++)
    {
        if(a.get_id()== b[i].get_id() && a.get_title()==b[i].get_title())
        {
            b[i]=b[b.size()-1];
            b.pop_back();
            c.push_back(a);
        }
    }
}
void list_student(vector<SinhVien> &b)
{
    for(int i=0;i<b.size();i++)
    {
        cout<<b[i];
    }
}
int main()
{
    
    library a;
    SinhVien s;
    vector<library > b;
    vector<SinhVien> c;
    while(1)
    {
        cout<<"1.them sach"<<endl;
        cout<<"2.xoa sach"<<endl;
        cout<<"3.tim sach"<<endl;
        cout<<"4.danh sach sach"<<endl;
        cout<<"5.muon sach"<<endl;
        cout<<"6.tra sach"<<endl;
        cout<<"7.danh sach sv"<<endl;
        cout<<"8.thoat"<<endl;
        int lc;
        cout<<"nhap lua chon :";
        cin>>lc;
        switch (lc)
        {
            case 1:
                add_book(a,b);
                break;
            case 2:
            {
                if(b.size()>0)
                delete_book(b);
            }
            break;
            case 3 : search_book(b);
                break;
            case 4: list_book(b);
                break;
            case 5: muon_sach(s,c,b);
                break;
            case 6: tra_sach(a,c,b);
                break;
            case 7: list_student(c);
                break;
            case 8: exit(0);
                break;
        }

    }
}