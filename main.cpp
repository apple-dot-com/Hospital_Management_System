// C++ program to implement the Hospital 
// Management System 

#include<iostream> 
#include<string>
#include<vector>
#include<algorithm>
using namespace std;

// Store the data of Hospital 

class User {
private:
	string account;
	string password;
	int func;//1hospital 2patient
public:
	void w_account(string acc)
	{
		this->account = acc;
	}
	void w_password(string pass)
	{
		this->password = pass;
	}
	void w_func(int f)
	{
		if (f == 1 || f == 2)
		{
			this->func = f;
		}
	}
	bool check_acc(string acc)
	{
		if (this->account == acc)
		{
			return true;
		}
		else
		{
			return false;
		}
	}
	bool check_pas(string pas)
	{
		if (this->password == pas)
		{
			return true;
		}
		else
		{
			return false;
		}
	}
	int get_func()
	{
		return this->func;
	}
};

class Hospital {
private:
	string H_name;
	string H_location;
	int H_beds;
	float H_rating;
	string H_contact;
	string H_docname;
	int H_price;
public:
	//read data
	string hname()
	{
		return this->H_name;
	}
	string hlocation()
	{
		return this->H_location;
	}
	int hbeds()
	{
		return this->H_beds;
	}
	float hrating()
	{
		return this->H_rating;
	}
	string contact()
	{
		return this->H_contact;
	}
	string hdocname()
	{
		return this->H_docname;
	}
	int price()
	{
		return this->H_price;
	}

	//write data
	void w_hname(string hname)
	{
		this->H_name = hname;
	}
	void w_hlocation(string hlocation)
	{
		this->H_location = hlocation;
	}
	void w_hbeds(int hbeds)
	{
		this->H_beds = hbeds;
	}
	void w_hrating(float hrating)
	{
		this->H_rating = hrating;
	}
	void w_contact(string contact)
	{
		this->H_contact = contact;
	}
	void w_hdocname(string hdocname)
	{
		this->H_docname = hdocname;
	}
	void w_price(int price)
	{
		this->H_price = price;
	}
};

// Stores the data of Patient 
class Patient : public Hospital {
private:
	string P_name;
	int P_id;
public:
	string pname()
	{
		return this->P_name;
	}
	int pid()
	{
		return this->P_id;
	}

	void w_pname(string pname)
	{
		this->P_name = pname;
	}
	void w_pid(int pid)
	{
		this->P_id = pid;
	}
};

vector<Hospital> hospitals;
vector<Patient> patients;
vector<User> users;

// Hospital Data 
void PrintHospitalData(
	vector<Hospital>& hospitals)
{
	cout << "PRINT hospitals DATA:"
		<< endl;

	cout << "HospitalName	 "
		<< "Location	 "
		<< "Beds_Available	 "
		<< "Rating	 "
		<< "Hospital_Contact	 "
		<< "Doctor_Name	 "
		<< "Price_Per_Bed	 \n";

	for (int i = 0; i < 4; i++) {
		cout << hospitals[i].hname()
			<< "				 "
			<< "	 "
			<< hospitals[i].hlocation()
			<< "		 "
			<< hospitals[i].hbeds()
			<< "				 "
			<< hospitals[i].hrating()
			<< "		 "
			<< hospitals[i].contact()
			<< "			 "
			<< hospitals[i].hdocname()
			<< "				 "
			<< "	 "
			<< hospitals[i].price()
			<< "		 "
			<< endl;
	}

	cout << endl
		<< endl;
}

// Function to print the patient 
// data in the hospital 
void PrintPatientData(
	vector<Patient> &patients,
	vector<Hospital> &hospitals)
{
	cout << "PRINT patients DATA:"
		<< endl;
	cout << "Patient_Name	 "
		<< "Patient_Id	 "
		<< "Patient_Contact	 "
		<< "Alloted_Hospital	 "
		<< "Patient_Expenditure	 \n";

	for (int i = 0; i < 4; i++) {
		cout << patients[i].pname()
			<< "			 "
			<< "		 "
			<< patients[i].pid()
		<< "			 "
			<< "		 "
			<< patients[i].contact()
			<< "				 "
			<< hospitals[i].hname()
			<< "				 "
			<< patients[i].price()
			<< "		 "
			<< endl;
	}

	cout << endl
		<< endl;
}

// Comparator function to sort the 
// hospital data by name 
bool name(Hospital& A, Hospital& B)
{
	return A.hname() < B.hname();
}

// Function to sort the hospital 
// data by name 
void SortHospitalByName(
	vector<Hospital> hospitals)
{
	// Sort the date 
	sort(hospitals.begin(),
		hospitals.end(),
		name);

	cout << "SORT BY NAME:"
		<< endl
		<< endl;
	PrintHospitalData(hospitals);
}

// Comparator function to sort the 
// hospital data by rating 
bool rating(Hospital& A, Hospital& B)
{
	return A.hrating() > B.hrating();
}

// Function to sort the hospital 
// data by namerating 
void SortHospitalByRating(vector<Hospital> hospitals)
{
	sort(hospitals.begin(),
		hospitals.end(),
		rating);

	cout << "SORT BY Rating:"
		<< endl
		<< endl;

	PrintHospitalData(hospitals);
}

// Comparator function to sort the 
// hospital data by Bed Available 
bool beds(Hospital& A, Hospital& B)
{
	return A.hbeds() > B.hbeds();
}

// Function to sort the hospital 
// data by Bed Available 
void SortByBedsAvailable(
	vector<Hospital> hospitals)
{
	sort(hospitals.begin(),
		hospitals.end(),
		beds);

	cout << "SORT BY Available Beds:"
		<< endl
		<< endl;

	PrintHospitalData(hospitals);
}

// Comparator function to sort the 
// hospital data by Bed Price 
bool beds_price(Hospital& A, Hospital& B)
{
	return A.price() < B.price();
}

// Function to sort the hospital 
// data by Bed Price 
void SortByBedsPrice(
	vector<Hospital> hospitals)
{
	sort(hospitals.begin(),
		hospitals.end(),
		beds_price);

	cout << "SORT BY Available Beds Price:"
		<< endl
		<< endl;

	PrintHospitalData(hospitals);
}

// Comparator function to sort the 
// hospital data by City 
void PrintHospitalBycity(
	string city, vector<Hospital> hospitals)
{
	cout << "PRINT hospitals by Name :"
		<< city << endl;

	cout << "HospitalName	 "
		<< "Location	 "
		<< "Beds_Available	 "
		<< "Rating	 "
		<< "Hospital_Contact	 "
		<< "Doctor_Name	 "
		<< "Price_Per_Bed	 \n";

	for (int i = 0; i < 4; i++) {

		if (hospitals[i].hlocation() != city)
			continue;
		cout << hospitals[i].hname()
			<< "				 "
			<< "	 "
			<< hospitals[i].hlocation()
			<< "		 "
			<< hospitals[i].hbeds()
			<< "				 "
			<< hospitals[i].hrating()
			<< "		 "
			<< hospitals[i].contact()
			<< "			 "
			<< hospitals[i].hdocname()
			<< "			 "
			<< "		 "
			<< hospitals[i].price()
			<< "		 "
			<< endl;
	}
	cout << endl
		<< endl;
}

// Function to implement Hospital 
// Management System 
void HospitalManagement(
	string patient_Name[], int patient_Id[],
	string patient_Contact[], int bookingCost[],
	string hospital_Name[], string locations[], int beds[],
	float ratings[], string hospital_Contact[],
	string doctor_Name[], int prices[])
{
	// Stores the Hospital data 
	// and user data 

	// Create Objects for hospital 
	// and the users 
	Hospital h;

	// Initialize the data 
	for (int i = 0; i < 4; i++) {
		h.w_hname(hospital_Name[i]);
		h.w_hlocation(locations[i]);
		h.w_hbeds(beds[i]);
		h.w_hrating(ratings[i]);
		h.w_contact(hospital_Contact[i]);
		h.w_hdocname(doctor_Name[i]);
		h.w_price(prices[i]);
		hospitals.push_back(h);
	}

	// Stores the patient data 
	Patient p;

	// Initialize the data 
	for (int i = 0; i < 4; i++) {
		p.w_pname(patient_Name[i]);
		p.w_pid(patient_Id[i]);
		p.w_contact(patient_Contact[i]);
		p.w_price(bookingCost[i]);
		patients.push_back(p);
	}
}

int login(vector<User> users)
{
	string account;
	string password;
	cout << "�������˺ţ�" << endl;
	cin >> account;
	cout << "���������룺" << endl;
	cin >> password;
	int succ = 0;
	for (int i = 0; i < users.size(); i++)
	{
		if (users[i].check_acc(account))
		{
			succ = 1;
			if (users[i].check_pas(password))
			{
				cout << "��¼�ɹ���" << endl << endl;
				return users[i].get_func();
			}
			else
			{
				cout << "�������������" << endl << endl;
			}
		}
	}
	if (succ != 1)
	{
		cout << "�˺Ų����ڣ�" << endl << endl;
	}
	return 0;
}

int regi()
{
	User user;
	string acc;
	string pas;
	int type;
	cout << "������ע����û�����" << endl;
	cin >> acc;
	cout << "������ע������룺" << endl;
	cin >> pas;
	cout << "������ע���˺ŵ����ͣ�1.ҽԺ 2.����" << endl;
	cin >> type;
	if (type != 1 && type != 2)
	{
		cout << "�Ƿ����룡" << endl << endl;
		return 0;
	}
	for (int i = 0; i < users.size(); i++)
	{
		if (users[i].check_acc(acc))
		{
			cout << "���û����ѱ�ע�ᣡ" << endl << endl;
			return 0;
		}
	}
	user.w_account(acc);
	user.w_func(type);
	user.w_password(pas);
	users.push_back(user);
	cout << "ע��ɹ���" << endl << endl;
	return 0;
}

void UI(int* stage, string patient_Name[], int patient_Id[],
	string patient_Contact[], int bookingCost[],
	string hospital_Name[], string locations[], int beds[],
	float ratings[], string hospital_Contact[],
	string doctor_Name[], int prices[])
{
	cout << "*��ӭʹ��ҽԺ����ϵͳ��*" << endl;
	cout << endl;
	cout << "��ѡ���ܣ�" << endl;
	if (*stage == 0)//login
	{
		cout << "1.��Ҫ��½  2.��Ҫע��  3.�˳�����" << endl;
		int tmp;
		cin >> tmp;
		cout << endl;
		switch (tmp)
		{
		case 1:
			*stage = login(users);
			break;
		case 2:
			regi();
			break;
		case 3:
			exit(0);
			break;
		default:
			cout << "�Ƿ����룡" << endl;
		}
	}
	if (*stage == 1)//hospital
	{
		cout << "ҽԺ���ܣ�1.��ʾ������Ϣ  2.�˳���¼" << endl;
		int tmp;
		cin >> tmp;
		cout << endl;
		switch (tmp)
		{
		case 1:
			PrintPatientData(patients, hospitals);
			break;
		case 2:
			*stage = 0;
			cout << endl;
			break;
		default:
			cout << "�Ƿ����룡" << endl;
		}
	}
	else if (*stage == 2)//patient
	{
		cout << "���߹��ܣ�1.��ʾҽԺ��Ϣ  2.��ҽԺ��������  3.��ҽԺ��������  4.��ʾ�ض�����ҽԺ  5.����λ������  6.����λ��������  7.�˳���¼" << endl;
		int tmp;
		cin >> tmp;
		cout << endl;
		switch (tmp)
		{
		case 1:
			PrintHospitalData(hospitals);
			break;
		case 2:
			SortHospitalByName(hospitals);
			break;
		case 3:
			SortHospitalByRating(hospitals);
			break;
		case 4:
			PrintHospitalBycity("Bangalore", hospitals);
			break;
		case 5:
			SortByBedsAvailable(hospitals);
			break;
		case 6:
			SortByBedsPrice(hospitals);
			break;
		case 7:
			*stage = 0;
			cout << endl;
			break;
		default:
			cout << "�Ƿ����룡" << endl;
		}
	}
}

// Driver Code 
int main()
{
	// Stores hospital data and 
	// the user data 
	string patient_Name[] = { "P1", "P2", "P3", "P4" };
	int patient_Id[] = { 2, 3, 4, 1 };
	string patient_Contact[]
		= { "234534XXX7", "234576XXX2", "857465XXX9",
			"567657XXX0" };
	int bookingCost[] = { 1000, 1200, 1100, 600 };

	string hospital_Name[] = { "H1", "H2", "H4", "H3" };
	string locations[] = { "Bangalore", "Bangalore",
						"Mumbai ", "Prayagraj" };
	int beds[] = { 4, 5, 6, 9 };
	float ratings[] = { 5.2, 4.1, 3.4, 5.9 };
	string hospital_Contact[]
		= { "657534XXX7", "298766XXX2", "324565XXX9",
			"343456XXX4" };
	string doctor_Name[] = { "D1", "D4", "D3", "D2" };
	int prices[] = { 100, 200, 100, 290 };

	// Function Call 
	HospitalManagement(
		patient_Name, patient_Id, patient_Contact,
		bookingCost, hospital_Name, locations, beds,
		ratings, hospital_Contact, doctor_Name, prices);

	//UI
	int stage = 0;
	while (true)
	{
		UI(&stage, patient_Name, patient_Id, patient_Contact,
			bookingCost, hospital_Name, locations, beds,
			ratings, hospital_Contact, doctor_Name, prices);
	}

	return 0;
}
