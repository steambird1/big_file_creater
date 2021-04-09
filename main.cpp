#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <string>
#include <conio.h>
#include <limits.h>
#include <time.h>
using namespace std;

#define megabyte_to_byte (1024*1024)
char buf[1024],mega[megabyte_to_byte];
long long tot=0,tof=0;

char ranchar(void) {
	static int ra = time(NULL);
	srand(ra);
	ra = rand();
	return char(ra%(CHAR_MAX-CHAR_MIN)+CHAR_MIN);
}

void aborts(void) {
	system("cls");
	cout << "Process aborted ( " << tof << " files and " << tot << " MB wrote )" << endl;
	getch();
	exit(1);
}

int main() {
	int fc,fsz;
	bool fwmode = false;
	char fwchar,tc;
	string s;
	system("title Seabird Big File Creater");
	cout << "Big file creater, by steambird 2021" << endl << endl << "How many file(s) would you like to create: ";
	cin>>fc;
	getchar();//feeding ENTER
	cout << "What's the name of file(s) ('%d' means id of file): ";
	getline(cin,s);
	cout << "What's the size of file creating (MB): ";
	cin>>fsz;
	getchar();//feeding ENTER
	cout << "What's the char to fill: ";
	tc=getchar();
	fwmode = true;
	system("cls");
	FILE *f;
	cout << "Preparing ..." << endl;
	for (int i = 0; i < megabyte_to_byte; i++) mega[i]=tc;
	for (int i = 1; i <= fc; i++) {
		sprintf(buf,s.c_str(),i);
		f=fopen(buf,"w");
		for (int j = 0; j < fsz; j++) {
			system("cls");
			if (kbhit()) aborts();
			fputs(mega,f);
			cout << "Processing..." << endl << endl << "Proceed " << ++tot << " MB ( " << tof << " / " << fc << " )" << endl << "Writing: " << buf << endl << endl << "Press any key to abort";
		}
		tof++;
		fclose(f);
	}
	system("cls");
	cout << "Process successful ( " << tof << " files and " << tot << " MB wrote )" << endl;
	getch();
	return 0;
}
