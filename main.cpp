#include <iostream>
#include <vector>
#include <string>
#include <cstring>
#include <fstream>
#include <map>
#include<iomanip>
#include <unordered_map>
#include <conio.h>

#define ANSI_COLOR_RED     "\x1b[31m"
#define ANSI_COLOR_GREEN   "\x1b[32m"
#define ANSI_COLOR_YELLOW  "\x1b[33m"
#define ANSI_COLOR_BLUE    "\x1b[34m"
#define ANSI_COLOR_MAGENTA "\x1b[35m"
#define ANSI_COLOR_CYAN    "\x1b[36m"
#define ANSI_COLOR_RESET   "\x1b[0m"

using namespace std;
//Quy noi
class Book
 {
protected:
    string bookname;
    string author;
    string bookcode;
    int pages;

public:
    Book() 
	{}

    Book(string bookname, string author, string bookcode, int pages)
	 {
        this->bookname = bookname;
        this->author = author;
        this->bookcode = bookcode;
        this->pages = pages;
    }

    void PrintInfoBook() const
	 {
        cout << "\nTen sach: " << bookname;
        cout << "\nTac gia: " << author;
        cout << "\nMa sach: " << bookcode;
        cout << "\nTrang: " << pages << endl;
    }
    
    void PrintInfoBookFile(ofstream& outfile) const {
        // Ghi thông tin sách ra file
        outfile << "Ten sach: " << bookname << "\nTac gia: " << author << "\nMa sach: " << bookcode << "\nTrang: "<< pages << "\n";
    }
    
    void DocFile(ifstream &infile) 
	{
        getline(infile, bookname);
        getline(infile, author);
        getline(infile, bookcode);
        infile >> pages;
        infile.ignore(); // Để bỏ qua ký tự newline sau pages
    }

    void GetInformation() 
	{
        cin.ignore();
        cout << "\nNhap ten sach: ";
        getline(cin, bookname);
        cout << "\nNhap Tac Gia: ";
        getline(cin, author);
        cout << "\nNhap ma sach: ";
        getline(cin, bookcode);
        cout << "\nNhap so trang: ";
        cin >> pages;
    }
    
     void updateBookInfo(const string& newName, const string& newAuthor, const string& newCode, int newPageCount) 
	 {
        bookname = newName;
        author = newAuthor;
        bookcode = newCode;
        pages = newPageCount;
    }
    
 string getFullInfo() const 
    {
        return "Ten sach: " + bookname + "\nTac gia: " + author + "\nMa sach: " + bookcode + "\nSo trang: " + to_string(pages);
    }
    string GetterBookname() const 
	{
	 return bookname; 
	 }
    string GetterAuthor() const 
	{
	 return author; 
	 }
    string GetterBookcode() const 
	{ 
	return bookcode; 
	}
    int GetterPage() const
	 {
	 return pages; 
	 }
	 
};

void Cap_Nhat_Thong_Tin(vector<Book>& ds)
 {
    string maSach;
    cout << "Nhap ma sach de cap nhat thong tin: ";
    cin >> maSach;

    for (int i = 0; i < ds.size(); i++) 
	{
        if (maSach == ds[i].GetterBookcode()) 
		{
            cout << "Nhap thong tin moi cho sach: " << endl;
            string newName, newAuthor, newCode;
            int newPageCount;

            cout << "Nhap ten sach moi: ";
            cin.ignore();
            getline(cin, newName);

            cout << "Nhap tac gia moi: ";
            getline(cin, newAuthor);

            cout << "Nhap ma sach moi: ";
            getline(cin, newCode);

            cout << "Nhap so trang moi: ";
            cin >> newPageCount;

            // Cập nhật thông tin sách
            ds[i].updateBookInfo(newName, newAuthor, newCode, newPageCount);
            cout << "Cap nhat thong tin sach thanh cong!" << endl;
            return;
        }
    }

    cout << "Khong tim thay sach co ma sach la " << maSach << endl;
}

void Doc_File_Danh_Sach_Book(ifstream &filein, vector<Book> &ds_sach)
 {
 	
    while (!filein.eof())
	 {
        Book x;
        x.DocFile(filein);
        ds_sach.push_back(x);//xoa phan tu cuoi cung
        string temp;
        getline(filein, temp);
    }
}

void In_Danh_Sach_Sach(const vector<Book> &ds) 
{
	
    cout << "\n\n\t\t" << ANSI_COLOR_CYAN << "=================== DANH SACH SACH =========================" << ANSI_COLOR_RESET << endl;
    for (int j = 0; j < 75; j++) {
        cout << "_";
    }
    cout << endl;

    cout << "|" << ANSI_COLOR_YELLOW << "STT" << ANSI_COLOR_RESET << "|" << setw(24) << ANSI_COLOR_YELLOW << "Ten sach" << ANSI_COLOR_RESET << "|" << setw(20) << ANSI_COLOR_YELLOW << "Tac gia" << ANSI_COLOR_YELLOW <<"| Ma sach |"<<" So trang|" <<ANSI_COLOR_RESET<< endl;
    cout << "|___|___________________________|______________________|_________|_________|" << endl;

    for (int i = 0; i < ds.size(); i++) {
        cout << "|" << setw(3) << i + 1 << "|" << setw(27) << ds[i].GetterBookname() << "|" << setw(22) << ds[i].GetterAuthor() << "|" << setw(9) << ds[i].GetterBookcode() << "|" << setw(9) << ds[i].GetterPage() << "|" << endl;
        cout << "|___|___________________________|______________________|_________|_________|" << endl;
    }
    system("pause");
}

void Them_Thong_Tin_Sach(vector<Book> &ds)
 {
 	
    int n;
    cout << "\nNhap so luong sach can them: ";
    cin >> n;
    for (int i = 0; i < n; i++) {
        cout << "\nNhap Thong Tin Sach Thu " << i + 1 << ": ";
        Book temp;
        temp.GetInformation();
        ds.push_back(temp);
    }
}

void Xoa_Thong_Tin_Sach_Theo_Ten_Sach(vector<Book> &ds) 
{
	
    int n;
    cout << "\nNhap so quyen sach can xoa: ";
    cin >> n;
    for (int i = 0; i < n; i++) 
	{
        string x;
        cin.ignore();
        cout << "\nNhap ten quyen sach can xoa thu " << i + 1 << ": ";
        getline(cin, x);
        for (int j = 0; j < ds.size(); j++) 
		{
            if (strcasecmp(x.c_str(), ds[j].GetterBookname().c_str()) == 0)
			 {
                ds.erase(ds.begin() + j);
                cout << "Da xoa sach!\n";
                break;
            }
        }
    }
}

void Xoa_Thong_Tin_Sach_Theo_Ma_Sach(vector<Book> &ds) 
{
	
    int n;
    cout << "\nNhap so quyen sach can xoa: ";
    cin >> n;
    for (int i = 0; i < n; i++) 
	{
        string x;
        cin.ignore();
        cout << "\nNhap ma sach can xoa thu " << i + 1 << ": ";
        getline(cin, x);
        for (int j = 0; j < ds.size(); j++)
		 {
            if (strcasecmp(x.c_str(), ds[j].GetterBookcode().c_str()) == 0) 
			{
                ds.erase(ds.begin() + j);
                cout << "Da xoa sach!\n";
                break;
            }
        }
    }
}

void Tim_Kiem_Thong_Tin_Sach_Theo_Ten_Sach(const vector<Book> &ds)
 {
 	
    string s;
    cin.ignore();
    cout << "\nMoi ban nhap ten sach tim kiem: ";
    getline(cin, s);
    for (int i = 0; i < ds.size(); i++)
	 {
        if (strcasecmp(s.c_str(), ds[i].GetterBookname().c_str()) == 0) 
		{
            cout << "\nSach can tim la: ";
            ds[i].PrintInfoBook();
        }
    }
    system("pause");
}

void Tim_Kiem_Thong_Tin_Sach_Theo_Tac_Gia(const vector<Book> &ds) 
{
	
    string s;
    cin.ignore();
    cout << "\nMoi ban nhap ten tac gia tim kiem: ";
    getline(cin, s);
    for (int i = 0; i < ds.size(); i++) 
	{
        if (strcasecmp(s.c_str(), ds[i].GetterAuthor().c_str()) == 0) 
		{
            cout << "\nSach can tim la: ";
            ds[i].PrintInfoBook();
        }
    }
    system("pause");
}

void Tim_Kiem_Thong_Tin_Sach_Theo_Ma_Sach(const vector<Book> &ds) 
{
	
    string s;
    cin.ignore();
    cout << "\nMoi ban nhap ma sach tim kiem: ";
    getline(cin, s);
    for (int i = 0; i < ds.size(); i++) 
	{
        if (strcasecmp(s.c_str(), ds[i].GetterBookcode().c_str()) == 0) 
		{
            cout << "\nSach can tim la: ";
            ds[i].PrintInfoBook();
        }
    }
    system("pause");
}

void Ghi_Danh_Sach_Sach(ofstream &outfile, const vector<Book> &ds) 
{
	
    for (const auto& book : ds) 
	{
        outfile << book.GetterBookname()<< endl;
        outfile << book.GetterAuthor() << endl;
        outfile << book.GetterBookcode() << endl;
        outfile << book.GetterPage() << endl;
    }
}

bool KiemTraTenSach(const vector<Book>& ds_sach, const string& tenSach) 
{
	
    for (const Book& sach : ds_sach) 
	{
        if (sach.GetterBookname() == tenSach) 
		{
            return true; // Tìm thấy tên sách trong danh sách
        }
    }
    return false; // Không tìm thấy tên sách trong danh sách
}

Book timSachTheoTen(const vector<Book>& ds_sach, const string& tenSach) 
{
	
    for (const Book& sach : ds_sach) 
	{
        if (sach.GetterBookname() == tenSach) 
		{
            return sach;
        }
    }
    return Book();
    // Nếu không tìm thấy sách, bạn có thể trả về một sách mặc định hoặc xử lý theo ý của bạn
}

class TimKiemSach : public Book
{
	
public:
   Book Tim_Kiem_Thong_Tin_Sach_Theo_Ten_Sach();
   
   Book Tim_Kiem_Thong_Tin_Sach_Theo_Tac_Gia();
   
   Book Cap_Nhat_Thong_Tin();
   
   Book Tim_Kiem_Thong_Tin_Sach_Theo_Ma_Sach();
   
   Book Ghi_Danh_Sach_Sach();
   
   Book Xoa_Thong_Tin_Sach_Theo_Ten_Sach();
   
   Book Xoa_Thong_Tin_Sach_Theo_Ma_Sach();

    
};

// Thang noi
class BorrowInfo 
{
    private:
    	string studentName;
    	string studentID;
	protected:
    Book book;
    
public:
    BorrowInfo() {}
    
    string GetStudentName() const 
	{
	 return studentName; 
	}
    void SetStudentName(const string& name) 
	{
        studentName = name;
    }
    string GetStudentID() const 
	{ 
	return studentID; 
	}
    void SetStudentID(const string& id) 
	{
        studentID = id;
    }
    Book GetBorrowedBook() const 
	{
	 return book; 
	}
	
    BorrowInfo(const Book& book, const string& studentName, const string& studentID) : book(book), studentName(studentName), studentID(studentID) {}

    void PrintInfoBorrowInfo() const 
	{
        cout << "\nTen sinh vien: " << studentName;
        cout << "\nMa sinh vien: " << studentID;
        cout << "\nThong tin sach:";
        book.PrintInfoBook();
    }
    
     void PrintInfoBorrowInfoFile(ofstream& outfile) const {
        // Ghi thông tin mượn sách ra file
        outfile << "Ten sinh vien: " << studentName << "\nMa sinh vien: " << studentID << "\n";
        book.PrintInfoBookFile(outfile); // Ghi thông tin sách
    }

};

// Hàm để in thông tin sinh viên mượn sách
void In_Thong_Tin_Sinh_Vien_Muon_Sach(const vector<BorrowInfo>& borrowList,const vector<Book> &ds) 
{
    cout << "\n\n\t\t =================== DANH SACH SINH VIEN MUON SACH =========================\n";
    for (int j = 0; j < 72; j++) 
	{
        cout << "_";
    }
    cout << endl;

    for (int i = 0; i < borrowList.size(); i++) 
	{
        cout << "\nTen sinh vien: " << borrowList[i].GetStudentName();
        cout << "\nMa sinh vien: " << borrowList[i].GetStudentID(); 
        cout << "\nThong tin sach muon: ";
        string tenSach;
    cout << "\nNhap ten sach can xem thong tin sinh vien muon: ";
    cin.ignore();
    getline(cin, tenSach);

    // Tìm sách trong danh sách
    bool found = false;
    for (const Book& sach : ds) 
	{
        if (sach.GetterBookname() == tenSach)
		 {
            // Hiển thị thông tin sách
            sach.PrintInfoBook();
            found = true;
            
            // Hiển thị thông tin sinh viên mượn sách
            for (const BorrowInfo& borrowInfo : borrowList) 
			{
                if (borrowInfo.GetBorrowedBook().GetterBookname() == tenSach) 
				{
                    borrowInfo.PrintInfoBorrowInfo();
                }
            }
            break;
        }
    }

    if (!found) 
	{
        cout << "\nKhong tim thay sach co ten '" << tenSach << "' trong danh sach!\n";
    }
    system("pause");
    break;
    }
}

void In_Thong_Tin_Sinh_Vien_Muon_Sach_Ra_File(const vector<BorrowInfo>& borrowList, const vector<Book>& ds) 
{   
    string filename = "sinhvienmuonsach.txt";
    std::ifstream inputfile("sinhvienmuonsach.txt");
    std::ofstream outfile(filename);

    if (!outfile.is_open()) 
	{
        cout << "\nKhong the mo file de ghi!\n";
        return;
    }

    outfile << "\n\n\t\t =================== DANH SACH SINH VIEN MUON SACH =========================\n";
    for (int j = 0; j < 72; j++) 
	{
        outfile << "_";
    }
    outfile << endl;

    for (int i = 0; i < borrowList.size(); i++) 
	{
        outfile << "\nTen sinh vien: " << borrowList[i].GetStudentName();
        outfile << "\nMa sinh vien: " << borrowList[i].GetStudentID(); 
        outfile << "\nThong tin sach muon: ";
        string tenSach;
        cout << "\nNhap ten sach can xem thong tin sinh vien muon: ";
        cin.ignore();
        getline(cin, tenSach);

        // Tìm sách trong danh sách
        bool found = false;
        for (const Book& sach : ds) 
		{
            if (sach.GetterBookname() == tenSach)
			{
                // Hiển thị thông tin sách
                outfile << "\nThong tin sach: ";
                sach.PrintInfoBookFile(outfile);
                found = true;
                
                // Hiển thị thông tin sinh viên mượn sách
                for (const BorrowInfo& borrowInfo : borrowList) 
				{
                     for (const auto& sv :  borrowList) 
	            {
                         outfile << sv.GetStudentName()<< endl;
                         outfile << sv.GetStudentID() << endl;
                }
                    if (borrowInfo.GetBorrowedBook().GetterBookname() == tenSach) 
					{
                        outfile << "\nThong tin muon sach: ";
                        borrowInfo.PrintInfoBorrowInfoFile(outfile);
                    }
                }
                
                
                break;
            }
        }

        if (!found) 
		{
            outfile << "\nKhong tim thay sach co ten '" << tenSach << "' trong danh sach!\n";
        }
    }

    outfile.close();
    cout << "\nDa ghi danh sach sinh vien muon sach ra file '" << filename << "' thanh cong!\n";
}

void Xoa_Thong_Tin_Sinh_Vien_Muon_Sach(vector<BorrowInfo>& borrowList) 
{
    cin.ignore();
    cout << "\nNhap ten sinh vien: ";
    string studentName;
    getline(cin, studentName);

    cout << "\nNhap ten sach: ";
    string bookName;
    getline(cin, bookName);

    auto it = borrowList.begin();
    bool found = false;
    
    while (it != borrowList.end()) 
    {
        if (it->GetStudentName() == studentName && it->GetBorrowedBook().GetterBookname() == bookName) 
        {
            it = borrowList.erase(it);
            found = true;
            cout << "\nDa xoa thong tin sinh vien muon sach!\n";
            break;
        } else 
        {
            ++it;
        }
    }

    if (!found) {
        cout << "\nKhong tim thay thong tin sinh vien muon sach can xoa!\n";
    }
}

// ham nhap thong tin cho danh sach sach
void Nhap_Thong_Tin_Danh_Sach(vector<Book> &ds)
{
    Book x;
    x.PrintInfoBook();
    ds.push_back(x);
}

void Hien_Thi_Thong_Tin_Danh_Sach(vector<Book> &ds)
{
	
    for (int i = 0; i < ds.size(); i++)
    {
        cout << "\n\tThong tin sach thu " << i + 1 << " : ";
        ds[i].PrintInfoBook();
    }
    system("pause");
}
//Quy noi
// Thiet lap menu

void MenuSach(vector<Book> &ds_sach, vector<BorrowInfo> &borrowList)
{

    int luachon;
   while (true) 
   {
        system("cls");
        cout << "\n\n\t\t ============= QUAN LI =============";
        cout << "\n\t\t1. Nhap thong tin danh sach";
        cout << "\n\t\t2. Xuat thong tin danh sach ra file";
        cout << "\n\t\t3. Xuat thong tin danh sach ra man hinh";
        cout << "\n\t\t4. Tim kiem thong tin theo ten sach";
        cout << "\n\t\t5. Tim kiem thong tin theo ma sach";
        cout << "\n\t\t6. Cap nhat thong tin";
        cout << "\n\t\t7. Xoa thong tin theo ma sach";
        cout << "\n\t\t8. Xoa thong tin theo ten sach";
        cout << "\n\t\t9. In thong tin sinh vien muon sach";
        cout << "\n\t\t10. xoa thong tin sinh vien muon sach";
        cout << "\n\t\t11. In thong tin sinh vien muon sach ra file";
        cout << "\n\t\t12. Thoat chuong trinh va luu file";
        cout << "\nNhap lua chon:";
        cin >> luachon;
        
        if (luachon==12)
		{
        	break;
		}
		switch (luachon) 
		{
		case 1:
			{
                Them_Thong_Tin_Sach(ds_sach);
                 system("pause");
                break;
            }
        case 2: {
                ofstream outfile("DanhSachSach.txt");
                if (outfile.is_open()) 
				{
                    Ghi_Danh_Sach_Sach(outfile, ds_sach);
                    outfile.close();
                    cout << "\nDa ghi danh sach sach ra file 'DanhSachSach.txt' thanh cong!\n";
                } else 
				{
                    cout << "\nKhong the mo file de ghi!\n";
                }
                system("pause");
                break;
            }
		case 3:
			{
			
               In_Danh_Sach_Sach(ds_sach);
                system("pause");
                break;
           } 
        case 4:
        	{
        	   Tim_Kiem_Thong_Tin_Sach_Theo_Ten_Sach(ds_sach);
        	    system("pause");
                break;
            }
        case 5:    
            {
               Tim_Kiem_Thong_Tin_Sach_Theo_Ma_Sach(ds_sach);
                system("pause");
                break;
            }
        case 6:
        	{
			
            Cap_Nhat_Thong_Tin(ds_sach);
             system("pause");
                break;
            }
        case 7:
                Xoa_Thong_Tin_Sach_Theo_Ma_Sach(ds_sach);
                 system("pause");
                break;
        case 8:
        	{
			
                Xoa_Thong_Tin_Sach_Theo_Ten_Sach(ds_sach);
                 system("pause");
                break;
            }
       case 9:
	       {

                In_Thong_Tin_Sinh_Vien_Muon_Sach(borrowList, ds_sach);
                system("pause");
                break;
           }
        case 10:
		   {
		
                Xoa_Thong_Tin_Sinh_Vien_Muon_Sach(borrowList);
                system("pause");
              	break;
	     	}
        case 11:
        	{
                In_Thong_Tin_Sinh_Vien_Muon_Sach_Ra_File(borrowList, ds_sach);
                system("pause");
        	break;
           }
            default:
                cout << "\nLua chon khong hop le. Vui long chon lai.\n";
                system("pause");
                break;        
        }
}
}




// Cấu trúc để lưu trữ thông tin sinh viên mượn sách

//Thang noi
void Menusach(vector<Book> &ds_sach, vector<BorrowInfo> &borrowList) 
{
    int luachon1;
    while (true) 
	{
        system("cls");
        cout << "\n\n\t\t ================== QUAN LI SACH =================";
        cout << "\n\t\t0. GHI DANH SACH SACH RA MAN HINH";
        cout << "\n\t\t1. GHI DANH SACH SACH RA FILE";
        cout << "\n\t\t2. TIM KIEM SACH THEO TEN";
        cout << "\n\t\t3. TIM KIEM SACH THEO TEN TAC GIA";
        cout << "\n\t\t4. TIM KIEM SACH THEO MA SACH";
        cout << "\n\t\t5. XEM THONG TIN SINH VIEN MUON SACH";
        cout << "\n\t\t6. THEM THONG TIN SINH VIEN MUON SACH";
        cout << "\n\t\t7. THOAT";
        cout << "\n\nMoi ban nhap lua chon: ";
        cin >> luachon1;

        if (luachon1 == 7) 
		{
            break;
        }

        switch (luachon1) 
		{
            case 0:
                In_Danh_Sach_Sach(ds_sach);
                 system("pause");
                break;
            case 1: 
			{
                ofstream outfile("DanhSachSach.txt");
                if (outfile.is_open()) 
				{
                    Ghi_Danh_Sach_Sach(outfile, ds_sach);
                    outfile.close();
                    cout << "\nDa ghi danh sach sach ra file 'DanhSachSach.txt' thanh cong!\n";
                } else 
				{
                    cout << "\nKhong the mo file de ghi!\n";
                }
                system("pause");
                break;
            }
            case 2:
            {
				
                Tim_Kiem_Thong_Tin_Sach_Theo_Ten_Sach(ds_sach);
                 system("pause");
                break;
            }
            case 3:
            {
                Tim_Kiem_Thong_Tin_Sach_Theo_Tac_Gia(ds_sach);
                 system("pause");
                break;
            }
            case 4:
            {
                Tim_Kiem_Thong_Tin_Sach_Theo_Ma_Sach(ds_sach);
                system("pause");
                break;
            }
            case 5:
            {	
                In_Thong_Tin_Sinh_Vien_Muon_Sach(borrowList, ds_sach);
                system("pause");
                break;
            }
            case 6: 
			{
                BorrowInfo borrowInfo;
                cin.ignore();
                cout << "\nNhap ten sinh vien: ";
                string name;
                getline(cin, name);
                borrowInfo.SetStudentName(name);
                
                cout << "\nNhap ma sinh vien: ";
                string id;
                getline(cin, id);
                borrowInfo.SetStudentID(id);

                while (true) 
				{
                    string tenSach;
                    cout << "\nNhap ten sach muon: ";
                    getline(cin, tenSach);

                    // Kiểm tra xem tên sách đã tồn tại trong danh sách mượn chưa
                    bool found = false;
                    for (const BorrowInfo& info : borrowList) 
					{
                        if (info.GetBorrowedBook().GetterBookname() == tenSach) 
						{
                            found = true;
                            break;
                        }
                    }

                    if (found) 
					{
                        cout << "\nSach da duoc muon. Vui long chon sach khac!\n";
                    } else 
					{
                        // Gán sách mượn vào borrowInfo
                        for (const Book& sach : ds_sach) 
						{
                            if (sach.GetterBookname() == tenSach) 
							{
                                borrowInfo.GetBorrowedBook() = sach;
                                borrowList.push_back(borrowInfo);
                                cout << "\nDa them thong tin sinh vien muon sach!\n";
                                break;
                            }
                        }
                        break;
                    }
                }
                system("pause");
                break;
            }
        case 7:
        {
        	break;
            default:
                cout << "\nLua chon khong hop le. Vui long chon lai.\n";
                system("pause");
                break;
        }
        }
    }
}

//Quy noi
struct TaiKhoan 
{
    string tenDangNhap;
    string matKhau;
};

void taiTaiKhoan(const string& filePath, unordered_map<string, string>& taiKhoan) 
{
	
    ifstream file(filePath);
    string tenDangNhap, matKhau;
    while (file >> tenDangNhap >> matKhau) 
	{
        taiKhoan[tenDangNhap] = matKhau;
    }
    file.close();
}

bool dangNhap(const unordered_map<string, string>& taiKhoan) 
{
	
    string tenDangNhap, matKhau;
    cout << "Nhap tai khoan admin: ";
    cin >> tenDangNhap;
    cout << "Nhap mat khau: ";
    cin >> matKhau;
    
    auto it = taiKhoan.find(tenDangNhap);
    if (it != taiKhoan.end() && it->second == matKhau) 
	{
        return true;
    } else 
	{
        cout << "Tên đăng nhập hoặc mật khẩu không đúng!" << endl;
        return false;
    }
}

//Quy noi

void QuanLy(vector<Book> &ds_sach, vector<BorrowInfo> &borrowList, string filein, string filePath,string fileTaiKhoan)
{
	
unordered_map<string, string> taiKhoan;
    taiTaiKhoan(fileTaiKhoan, taiKhoan);
    int choice;
    thulai:
    while (true)
    {
        cout << "----- QUAN LY -----" << endl;
        cout << "1. Thu vien sach" << endl;
        cout << "2. Quan ly" << endl;
        cout << "3. Thoat" << endl;
        cin >> choice;
        switch (choice)
        { 
        case 1:
            Menusach(ds_sach,borrowList);
            break;
        case 2:
           if(dangNhap(taiKhoan)) 
           {
                MenuSach(ds_sach,borrowList);
               
            }
            break;
        case 3:
        	cout << " Ban co the xem file code cpp o : https://github.com/QuyVu2005/Nhom6-Vu-Ngoc-Quy-va-Nguyen-Duc-Thang " << endl;
        system("pause");
        	goto thulai;
        default:
            cout << "Lua chon khong hop le!" << endl;
            break;
        }
    }
}

string tenTaiKhoan="";

void Login(){
	
    int choice;
    string filetaikhoan = "D:/taikhoan.txt";
    map<string, string> maptk;
    
    std::ifstream inputFile("D:/taikhoan.txt");
    string key, value;
    while(inputFile >> key >> value) 
	{
        maptk.insert(make_pair(key,value));
    }
    inputFile.close();
    

    while (tenTaiKhoan.length()==0)
    {
        cout << "----- Dang nhap -----" << endl;
        cout <<ANSI_COLOR_GREEN<< "1. Dang nhap" <<ANSI_COLOR_RESET<< endl;
        cout <<ANSI_COLOR_GREEN<< "2. Dang ki" <<ANSI_COLOR_GREEN<< endl;
        cout <<ANSI_COLOR_GREEN<< "3. Thoat" <<ANSI_COLOR_GREEN<< endl;
        cin >> choice;
        switch (choice)
        {
       case 1:
	{
    string tk,mk;
    cout<<"Nhap tai khoan:";
    cin>>tk; //tai khoan
            
    auto tim=maptk.find(tk);
    if (tim==maptk.end()) 
	{
        cout<<"Tai khoan khong ton tai"<<endl;
        break;
    }
    
    cout<<endl<<"Nhap mat khau:";
    cin>>mk; //mat khau
            
    if (maptk[tk]==mk) 
	{
        tenTaiKhoan=tk;
        cout<<"Dang nhap thanh cong"<<endl;
        
        // Ghi thông tin đăng nhập vào file nếu đăng nhập thành công
        std::ofstream outputFile(filetaikhoan, std::ofstream::app);
        outputFile << tk << ' ' << mk << '\n';
        outputFile.close();
    }
    else 
    {
        cout<<"Dang nhap that bai"<<endl;
    }
    break;
}
case 2:
{
    string tk,mk;
    cout<<"Dang ki"<<endl;
    cout<<"Nhap tai khoan:";
    cin>>tk; //tai khoan
    
    // Kiểm tra xem tài khoản đã tồn tại chưa
    auto tim=maptk.find(tk);
    if (tim != maptk.end()) 
	{
        cout<<"Tai khoan da ton tai"<<endl;
        break;
    }
    
    cout<<endl<<"Nhap mat khau:";
    cin>>mk; //mat khau
            
    // Mở file để ghi thông tin tài khoản mới
    std::ofstream outputFile(filetaikhoan, std::ofstream::app);
    // Ghi thông tin tài khoản mới vào file
    outputFile << tk << ' ' << mk << '\n';
    outputFile.close();
    
    // Cập nhật thông tin trong bộ nhớ
    maptk.insert(make_pair(tk,mk));
    tenTaiKhoan=tk;
    cout<<"Dang ki thanh cong"<<endl; 
    break;
}
        case 3:
            break;
        default:
            cout << "Lua chon khong hop le!" << endl;
        }
    }
}

//Quy noi
int main()
{
    

    string filein = "D:\\DanhSachSach.txt";
    string fileTaikhoan = "D:\\accounts.txt";
    string filePath;
    
    vector<Book> ds_sach;
     vector<BorrowInfo> borrowList;
    string filename="D:\\sinhvienmuonsach.txt";
    
    Login();
    
    if (tenTaiKhoan.length()>0)
    {
         QuanLy(ds_sach, borrowList, filein, filePath,fileTaikhoan);

    cout << " Ban co the xem file code cpp o : https://github.com/QuyVu2005/Pbl1.Nhom6-Vu-Ngoc-Quy-va-Nguyen-Duc-Thang " << endl;
    system("pause");
    }
  ifstream bookFile(filein);
    if (bookFile.is_open()) 
    {
        Doc_File_Danh_Sach_Book(bookFile, ds_sach);
        bookFile.close();
    } else 
    {
        cout << "Không thể mở file " << filein << endl;
    }

    
      Menusach(ds_sach,borrowList);
    

    return 0;
}
// khuôn mẫu hàm, khuôn mẫu lớp => tiết kiệm thời gian tuy tốn tài nguyên nhưng cũng có thể hỗ trợ được nhiều hàm con riêng dễ bảo trì,dễ kiểm soát 