/*
*****************************************************
 Project on
 Car sales and service management system
******************************************************
*/

#include<iostream.h>
#include<conio.h>
#include<stdio.h>
#include<process.h>
#include<fstream.h>
#include<dos.h>
#include<string.h>
#include<ctype.h>

class cars
{
   public:
 // FOR CAR REGISTRATION.....
 //{
   char carname[20];
   char brand[20];
   char model[20];
   long long car_cost;
   char colour[10];
   char fuel_type[15];
   int id;//  the id of the car;
// }

  fstream f1,f2,f3,f4;
  //id1;// to show the selected car in vehicles;

// FOR BILLING(TRANSACTION).....
//{
   char name[20];
   char man,manp; //For admin and customer;

   float age;
   char address[50];
   long long phoneno;
   char email[50];
   char car_type[10];
   int id_purcar;        //  id Selection for purchase of car;
   int id_cust;         //   For locating that customer;
 //}
   char service[5][30];
   float price[10];
   int count;
   float total;
   float amount;
   float amount2;

   public:
   void manac();
   void mainmenu();
   void addrec();
   void mainmenu_tasks();
   int check_id();
   void register_record();
   void edit_record();
   void car_vehicles();    //It will come under Vehicle option;
   void car_transaction();
   void customer();
   void car_billing(int purcar,char name1[],char address1[],float age1,long long phoneno1 );   // TRANSACTION BIll PRINTOUT;
   void car_service();
   void car_billing2();  // BILL FOR SERVICE PRINTOUT;
   void deposit(long long total);
   void car_customer();
   void about_us();
   void colours(int n);
   void password();
   void help();             //   FOR help ;

}  s1; // The object;

 void cars::mainmenu()         //THIS IS THE MAINMENU;
 {
   s1.colours(1);
   textcolor(138);
   gotoxy(21,2);
   cprintf("CAR SALES AND SERVICE MANAGEMENT SYSTEM");cout<<"\n"; textcolor(3);
   cprintf("--------------------------------------------------------------------------------");
   cprintf("________________________________________________________________________________ ");

    gotoxy(1,1);
    if(manp=='a')
    cprintf("ADMIN");
    else
    cprintf("CUSTOMER");

 gotoxy(1,5);
 textbackground(3);
 cprintf("                                                                                ");

 textcolor(RED);
 gotoxy(2,5);
 cprintf("F");
 textcolor(BLACK);
 gotoxy(3,5);
 cprintf("ile");

 textcolor(RED);
 gotoxy(16,5);
 cprintf("V");
 textcolor(BLACK);
 gotoxy(17,5);
 cprintf("ehicles");

 textcolor(RED);
 gotoxy(34,5);
 cprintf("S");
 textcolor(BLACK);
 gotoxy(35,5);
 cprintf("ervice");

 textcolor(RED);
 gotoxy(51,5);
 cprintf("T");
 textcolor(BLACK);
 gotoxy(52,5);
 cprintf("ransaction");

 textcolor(RED);
 gotoxy(73,5);
 cprintf("H");
 textcolor(BLACK);
 gotoxy(74,5);
 cprintf("elp\n");

 textcolor(RED);
 gotoxy(58,24);
 cprintf("(Press (H/h) for Help)");
 gotoxy(71,1);
 cprintf("Exit(E/e)");

 }
 void cars::mainmenu_tasks()  // THESE ARE THE TASKS PROVIDED BY THE MAINMENU;
 {
  char choice,choiceV;
  gotoxy(2,24);
  cprintf("Enter your choice:");
  cin>>choice;

	switch(choice)
 {
		       case 'f':case 'F':
	      {        if(manp=='c')
		       { clrscr();
			 s1.colours(0);
			 gotoxy(30,12);
			 cprintf("ONLY FOR ADMIN\n");
			 getch();
			 mainmenu();
			 mainmenu_tasks();
		      }
		       gotoxy(1,6);
		       cprintf("R:Register");
		       gotoxy(1,7);
		       cprintf("E:Edit    ");
		       gotoxy(1,8);
		       cprintf("B:Back  ");
		     A:

		       gotoxy(3,24);
		       cprintf("Enter your choice:");
		       cin>>choiceV;

	  switch(choiceV)
			   // VEHICLE TASKS;

       {

       case 'r':case 'R':
	   {   clrscr();
	       register_record();
	       break;
	   }
       case 'e':case 'E':
	     {  edit_record();
		break;
	     }
	case 'b':case 'B':
	     {   mainmenu();
		 mainmenu_tasks();
	     }

	default:
	      {  cprintf("Enter any valid choice:");
		 goto A;
	      }
	   }  //  CHOICEV (FILE) END BLOCK;
	 break;

       } // CASE File END BLOCK;
	 case 'v':case 'V':
       {
	car_vehicles();    //TO DISPLAY ALL THE VEHICLES;
	break;
       }
       case 't':case 'T':
       {  if(manp=='a')
		       { clrscr();
			 s1.colours(0);
			 gotoxy(30,12);
			 cprintf("ONLY FOR CUSTOMERS\n");
			 getch();
			 mainmenu();
			 mainmenu_tasks();
		      }
	car_transaction();
	break;
       }
       case 's':case 'S':
       {  if(manp=='a')
		       { clrscr();
			 s1.colours(0);
			 gotoxy(30,12);
			 cprintf("ONLY FOR CUSTOMERS\n");
			 getch();
			 mainmenu();
			 mainmenu_tasks();
		      }
	car_service();
	break;
       }
       case 'h':case 'H':
       {
       help();
       getch();
       clrscr();
       mainmenu();
       mainmenu_tasks();
       break;
       }
       case 'e': case 'E':
	{
	  exit(0);
	}
       default:
       { clrscr();
       cout<<"Wrong choice";
       getch();
       mainmenu();
       mainmenu_tasks();
       }
 }   // CHOICE END BLOCK;

 } // END OF MAINMENU_TASKS FUNCTION BLOCK;

 void cars::manac()
 {

  A:
  s1.colours(0);
  textcolor(10);
  clrscr();
  cout<<"\n\nYou are an:";
  cout<<"\n\n a:Admin\n";
  cout<<"\n b:Customer";
  gotoxy(12,3);
  cin>>man;
  if(man=='a')
  { manp='a';
  password();
  }
  else if(man=='b')
  manp='c';
  else
  { gotoxy(20,10);
  cout<<"Enter correct option:";
  sleep(1);
  goto A;}
 }


 void main()                    // MAIN() STARTS;
{
 s1.manac();
 s1.mainmenu();
 s1.mainmenu_tasks();
}


  void cars::register_record()
  {
     lab:
     char ch;
     gotoxy(35,2);
     cprintf("REGISTER CAR");cout<<"\n";
     ofstream ofile;
     ofile.open("Added_record.dat",ios::app);
     s1.addrec();    // REGISTRING THE DETAILS HERE;

     ofile.write((char *)&s1,sizeof(s1));
     clrscr();
  gotoxy(20,10);
  cprintf("File is saved");
  gotoxy(20,14);
  cprintf("Do you want to enter more:");
  cin>>ch;
  clrscr();
  if(ch=='y'|| ch=='Y')
  {
   clrscr();
   ofile.close();
   goto lab;
  }
  else
  {
   ofile.close();
   mainmenu();
   mainmenu_tasks();
  }
  ofile.close();
}

 void cars::edit_record()
  {
   s1.colours(7);
   int j=0,id1=0;
   L:
   fstream ifile;
   ifile.open("Added_record.dat",ios::binary||ios::in);

   if(ifile)
   cout<<"Working";
   else
   {
   cout<<"File is empty";
   getch();
   mainmenu();
   mainmenu_tasks();
   }
   gotoxy(30,2);
   cprintf("AVAILABLE VEHICLES");
   gotoxy(24,10);

   j=0;
   while(ifile.read((char *)&s1,sizeof(s1)))
   {
     gotoxy(20,8);
     cprintf("ID.no");
     gotoxy(40,8);
     cprintf("Vehicles");cout<<"\n";
     cout<<"--------------------------------------------------------------------------------";
     gotoxy(20,10+j);
     cout<<s1.id;
     gotoxy(40,10+j);
     cout<<s1.carname;

     j++;
   }
   ifile.close();
   ifile.open("Added_record.dat",ios::out|ios::in);
   gotoxy(10,22);
   cprintf("Enter any id to edit car:");
   gotoxy(10,24);
   cprintf("Press 98 to go back:");
   cin>>id1;
   if(id1==98)
     { mainmenu();
       mainmenu_tasks();
     }
   clrscr();
   while(ifile.read((char*)&s1,sizeof(s1)))
   {   if (s1.id==id1)
     {
       cout<<"\n   Enter the new details"<<endl;
      int pos= -1*sizeof(s1);
      ifile.seekp(pos,ios::cur);
      s1.addrec();
      ifile.write((char*)&s1,sizeof(s1));
      ifile.close();

  clrscr();
  gotoxy(20,10);
  cprintf("File is saved");

  s1.mainmenu();
  s1.mainmenu_tasks();
     }
     }
      if(id1!=s1.id)
      cout<<"\n\n\n\n\n\n\t\t\t\t TRY AGAIN ";    //IF SUPPOSE OPTION IS WRONG
      getch();
      clrscr();
      goto L;

    }
 void cars::addrec()
 {
     id=check_id();
    gotoxy(4,5);cprintf("Enter the brand name      : ");
	     gets(brand);
    gotoxy(4,7);cprintf("Enter the Car name        : ");
	     gets(carname);
    gotoxy(4,9);cprintf("Enter the model           :");
	     gets(model);
    gotoxy(4,11);cprintf("Enter the colour          :");
	     gets(colour);
    gotoxy(4,13);cprintf("Enter the fuel type       :");
	     gets(fuel_type);B:
	     gotoxy(4,15);
	     cout<<"                                        ";
    gotoxy(4,15);cprintf("Enter the vehicle cost    :");
	     cin>>car_cost;
	     if((car_cost<=0))
	     goto B;

	     cout<<id   ;
	     getch();

    }
  void cars::car_vehicles()          //   TO DISPLAY ALL THE VEHICLES;
  {
   clrscr();

   s1.colours(2);
   textcolor(1);
   int j=0;char ch3;
   B:
   ifstream file2;
    file2.open("Added_record.dat",ios::in|ios::binary);
   if(file2)
   cout<<"Working";
   else
   {
   cout<<"  File is empty";
   getch();
   mainmenu();
   mainmenu_tasks();
   }
   gotoxy(30,2);
   cprintf("AVAILABLE VEHICLES");
   gotoxy(24,10);
   j=0;
   while(file2.read((char *)&s1,sizeof(s1)))
   {
     gotoxy(20,8);
     cprintf("ID.no");
     gotoxy(40,8);
     cprintf("Vehicles");cout<<"\n";
     cout<<"--------------------------------------------------------------------------------";
     gotoxy(20,10+j);
     cout<<id;
     gotoxy(40,10+j);
     cout<<carname;

     j++;
   }
   file2.close();
   ifstream ifs;
   ifs.open("Added_record.dat",ios::binary||ios::in);
   int id1;
   gotoxy(10,22);
   cprintf("Enter any id to view the car:");
   gotoxy(10,24);
   cprintf("Press 98 to go back:");
   cin>>id1;
    if(id1==98)
     {  ifs.close();
       mainmenu();
       mainmenu_tasks();
     }
   clrscr();

   while(ifs.read((char*)&s1,sizeof(s1)))
   {  if (id1==s1.id)
     {
      gotoxy(34,3);
      cout<<"Details";
      gotoxy(22,7);
      cout<<"Carname    :"<<carname<<"\n";
      gotoxy(22,9);
      cout<<"Brand      :"<<brand<<"\n";
      gotoxy(22,11);
      cout<<"Model      :"<<model<<"\n";
      gotoxy(22,13);
      cout<<"Colour     :"<<colour<<"\n";
      gotoxy(22,15);
      cout<<"Fuel Type  :"<<fuel_type;
      gotoxy(22,17);
      cout<<"Cost       :"<<car_cost<<"\n";

     gotoxy(4,24);
     cprintf("Press B/b to go back:");
     cin>>ch3;
     clrscr();
     if(ch3=='b'|| ch3=='B')
     goto B;

    }
    } if(id1!=s1.id)
      cout<<"\n\n\n\n\n\n\t\t\t\t TRY AGAIN ";    //IF SUPPOSE OPTION IS WRONG
      getch();
      clrscr();
      goto B;
  }

 void cars::car_transaction()
 {
     clrscr();

     char name2[20];long long phoneno2; float age2;
     char address2[20]; int id_cust2; char email2[20];
     clrscr();
     ifstream file2;
    file2.open("Added_record.dat",ios::in|ios::binary);

   if(file2)
   cout<<"Working";
   else
   {cout<<"Sorry No cars Available";
    getch();
    mainmenu();
    mainmenu_tasks();
   }

  gotoxy(33,2);
  cprintf("Car Transaction");

  customer();

   strcpy(name2,name);age2=age;	 strcpy(address2,address);  phoneno2=phoneno;
   strcpy(email2,email);
   gotoxy(30,2);
   clrscr();
   cprintf("AVAILABLE VEHICLES");
   gotoxy(24,10);
   int j=0;
   while(file2.read((char *)&s1,sizeof(s1)))
   {
     gotoxy(20,8);
     cprintf("ID.no");
     gotoxy(40,8);
     cprintf("Vehicles");cout<<"\n";
     cout<<"--------------------------------------------------------------------------------";
     gotoxy(20,10+j);
     cout<<id;
     gotoxy(40,10+j);
     cout<<carname;

     j++;
   }
   file2.close();
   int purcar;
   gotoxy(4,20);
   cprintf("Enter the id of the car You want to BUY :");
   cin>>purcar;

   s1.car_billing(purcar,name2,address2,age2,phoneno2);
  }
   void cars::customer()
  {
  gotoxy(4,5);
  cprintf("Enter the customer name    :");
  gets(name);
  A:
  gotoxy(4,7);
  cout<<"                                          ";
  gotoxy(4,7);
  cprintf("Enter the Age              :");
  cin>>age;if((age<=0)||(age>90)) goto A;
  gotoxy(4,9);
  cprintf("Enter the address          :");
  gets(address);        B:
  gotoxy(4,11);
  cout<<"                                          ";
  gotoxy(4,11);
  cprintf("Enter the Contact number   :");
  cin>>phoneno; if(phoneno<=0) goto B;
  gotoxy(4,13);
  cprintf(" Enter the Email           :");
  cin>>email;
  }

  void cars::car_service()
 {
    char ser;   // Service variable;
    char type;
    count=0;
    s1.colours(6);

    clrscr();

  gotoxy(33,2);
  cprintf("Car Service");
  customer();
  gotoxy(4,15);
  cprintf(" Enter the Car type        :");
  cin>>car_type;
  lab2:
  clrscr();
  gotoxy(4,3);                      //   MENU STARTS HERE;
  cprintf("SERVICE TYPES :");
  gotoxy(4,5);
  cprintf("a.Wash");
  gotoxy(4,7);
  cprintf("b.Check");
  gotoxy(4,9);
  cprintf("c.Dent");
  gotoxy(4,11);
  cprintf("d.Paint");
  gotoxy(4,13);
  cprintf("e.Exit");
  gotoxy(4,24);
  cprintf("Choose any option:");
  cin>>type;

  switch(type)
  {
  case 'a':
  {
  clrscr();

  gotoxy(4,3);                      //   MENU STARTS HERE;
  cprintf("SERVICE TYPES :");
  gotoxy(4,5);
  cprintf("a.Car wash (Exterior)");
  gotoxy(4,7);
  cprintf("b.Car wash(Interior)");
  gotoxy(4,22);
  cprintf("Enter the service type:");
  cin>>ser;

  if(ser=='a')
  {
  strcpy(service[count],"Car wash (Exterior)");                 price[count]=2102;
  }
  else if(ser=='b')
  {
  strcpy(service[count],"Car wash (Interior)");                  price[count]=2132;
  }
  else
  {
   clrscr();
   cout<<"Invalid option";
   getch();
   goto lab2;
  }
  break;
   }
   case 'b':
  {    clrscr();
  gotoxy(4,3);
  cprintf("SERVICE TYPES :");
  gotoxy(4,5);
  cprintf("a.Oil Check and Filter Check");
  gotoxy(4,7);
  cprintf("b.Wheel and Break Check");
  gotoxy(4,9);
  cprintf("c.Complete Check");
  gotoxy(4,16);
  cprintf("Enter the service type:");
  cin>>ser;

  if(ser=='a')
  {
  strcpy(service[count],"Oil check and Filter check");                 price[count]=4102;
  }
  else if(ser=='b')
  {
  strcpy(service[count],"Wheel and break check");                      price[count]=2182;
  }
  else if(ser=='c')
  {
  strcpy(service[count],"Complete Check");                              price[count]=2172;
  }
  else
  {
   clrscr();
   cout<<"Invalid option";
   getch();
   goto lab2;
  }
  break;
  }
  case 'c':
  {          clrscr();
  gotoxy(4,3);
  cprintf("SERVICE TYPES :");
  gotoxy(4,5);
  cprintf("a.Bonnet Dent");
  gotoxy(4,7);
  cprintf("b.Trunk Dent");
  gotoxy(4,9);
  cprintf("c.Roof Dent");
  gotoxy(4,16);
  cprintf("Enter the service type:");
  cin>>ser;

  if(ser=='a')
  {
  strcpy(service[count],"Bonnet Dent");                         price[count]=5408;
  }
  else if(ser=='b')
  {
  strcpy(service[count],"Trunk Dent");                          price[count]=2122;
  }
  else if(ser=='c')
  {
  strcpy(service[count],"Roof Dent");                           price[count]=3142;
  }
  else
  {
   clrscr();
   cout<<"Invalid option";
   getch();
   goto lab2;
  }
  break;
    }
  case 'd':
   {      clrscr();
  gotoxy(4,3);
  cprintf("SERVICE TYPES :");
  gotoxy(4,5);
  cprintf("a.Hood Paint");
  gotoxy(4,7);
  cprintf("b.Front Bumpers Paint");
  gotoxy(50,5);
  cprintf("c.Trunk Paint");
  gotoxy(50,7);
  cprintf("d.Roof Paint");
  gotoxy(5,22);
  cprintf("Enter the service type:");
  cin>>ser;

  if(ser=='a')
  {
  strcpy(service[count],"Hood paint");                            price[count]=5182;
  }
  else if(ser=='b')
  {
  strcpy(service[count],"Bumper paint");                           price[count]=5152;
  }
  else if(ser=='c')
  {
  strcpy(service[count],"Trunk paint");                            price[count]=3172;
  }
  else if(ser=='d')
  {
  strcpy(service[count],"Roof paint");                             price[count]=2302;
  }
   else
  {
   clrscr();
   cout<<"Invalid option";
   getch();
   goto lab2;
  }
  break;
       }   //   End of case;
    case 'e':{ mainmenu();
	       mainmenu_tasks();
	       break;
	    }
    default:clrscr();
	    gotoxy(10,24);
	    cout<<"INvalid option:";
	    getch();
	    goto lab2;

	}   //   End of switch;
  v:
	char ch;
  gotoxy(20,20);
  cprintf("Do you want to continue the service:(Y/N)");
  cin>>ch;
  clrscr();

  if(ch=='y'|| ch=='Y')
  {
   clrscr();
   count++;
   goto lab2;
  }
  else if (ch=='N'||ch=='n')
  car_billing2();
  else
  {
  clrscr();
  cout<<"\n\n\n\nEnter valid choice";
  getch();
  goto v;
  }
  }    //  End of function;

 void cars::colours(int n)        // for background color
{
    int i=0,j=0;
   for (i=0; i<26; i++)
   {
       for (j=0; j<80; j++)
       cprintf(" ");
      textbackground(n);
   }
}

void cars::car_billing(int purcar,char name1[],char address1[],float age1,long long phoneno1)
{
   clrscr();
   s1.colours(0);
   long long total2;

   ifstream file2;

   file2.open("Added_record.dat",ios::in);
   cout<<purcar;

  while(file2.read((char*)&s1,sizeof(s1)))
  {
    if(s1.id==purcar)
    {
  textcolor(WHITE);
  gotoxy(1,1);

  cprintf(" ______________________________________________________________________________|");
  gotoxy(28,2);
  cprintf("  ULTRA RIDE MOTORS  ");
  gotoxy(20,3);
  cprintf("  __--__--__--__--__--__--__--__--__--__  ");
  gotoxy(30,4);
  cprintf("  SALES INFO   ");
  gotoxy(2,5);
  cprintf(" ------------------------------------------------------------------------------|");
  gotoxy(3,6);
  cprintf("NAME        : ");cout<<name1;
  gotoxy(3,7);
  cprintf("ADDRESS     : ");cout<<address1;
  gotoxy(3,8);
  cprintf("AGE         : ");cout<<age1;
  gotoxy(3,9);
  cprintf("CONTACT NO. : ");cout<<phoneno1;
  gotoxy(2,10);
  cprintf("------------------------------------------------------------------------------|");
  gotoxy(48,8);
  cprintf("CAR ID     :"  );cout<<purcar;
  gotoxy(48,6);
  cprintf("INVOICE NO :");cout<<"Bps@123";
  gotoxy(2,11);
  cprintf("______________________________________________________________________________|");
  gotoxy(5,12);
  cprintf("S.no :  |              DESCRIPTION :             |          PRICE :       |    ");
  gotoxy(5,15);
  cout<< "  1:               "<<carname;
  gotoxy(62,15);
  cout<<car_cost;
  gotoxy(2,13);
  cprintf("--------------------------------------------------------------------------------");
  gotoxy(60,24);          total=car_cost;
  cprintf("Total :");cout<<total;total2=total;

  for(int i=0;i<26;i++)
  {
  gotoxy(80,1+i);
  cprintf("|");
  }
  for(i=0;i<25;i++)
  {
  gotoxy(1,1+i);
  cprintf("|");
  }
  }
  }
  file2.close();
  getch();
  clrscr();
  deposit(total2);          // deposit function call statement;
  getch();
  clrscr();
  cout<<"\n\n\n\n\n\t\t\t\Please ViSiT AGain";
  getch();
  s1.mainmenu();
  s1.mainmenu_tasks();
}

void cars::car_billing2()
{
  s1.colours(0);
  textcolor(WHITE);
  clrscr();

  gotoxy(1,1);
  cprintf(" ______________________________________________________________________________|");
  gotoxy(28,2);
  cprintf("  ULTRA RIDE MOTORS  ");
  gotoxy(24,3);
  cprintf("  __--__--__--__--__--__--__--__--   ");
  gotoxy(30,4);
  cprintf("  SERVICE INFO   ");
  gotoxy(2,5);
  cprintf(" ------------------------------------------------------------------------------|");
  gotoxy(3,6);
  cprintf("NAME        :");cout<<name;
  gotoxy(3,7);
  cprintf("ADDRESS     :");cout<<address;
  gotoxy(3,8);
  cprintf("AGE         :");cout<<age;
  gotoxy(3,9);
  cprintf("CONTACT NO. :");cout<<phoneno;
  gotoxy(2,10);
  cprintf("------------------------------------------------------------------------------|");
  gotoxy(48,6);
  cprintf("INVOICE NO :");cout<<"Bps@123";
  gotoxy(2,11);
  cprintf("______________________________________________________________________________|");
  gotoxy(5,12);
  cprintf("S.no :  |              DESCRIPTION :             |          AMOUNT :       |    ");
  gotoxy(2,13);
  cprintf("--------------------------------------------------------------------------------");

  for(int j=0;j<=count;j++)
  {
    gotoxy(5,15+j);
    cout<<j+1<<":"<<"                    "<<service[j];
    gotoxy(62,15+j);
    cout<<price[j];
    total=total+price[j];
  }
  gotoxy(60,24);
  cprintf("Total :");cout<<total;
  for(int i=0;i<26;i++)
  {
  gotoxy(80,1+i);
  cprintf("|");
  }
  for(i=0;i<25;i++)
  {
  gotoxy(1,1+i);
  cprintf("|");
  }
  getch();
  clrscr();
  deposit(total);
  getch();
  mainmenu();
  mainmenu_tasks();
 }
  void cars::deposit(long long total)
{
  A:
  clrscr();
  gotoxy(15,8);
  cout<<"Bill:"<<total;
  gotoxy(15,10);
  cout<<"Please deposit money:";
  cin>>amount;
  if(amount<0)
  {
   goto A;
  }
  if(amount<total)
  {   b:
  clrscr();
  gotoxy(15,10);
  cout<<"Please deposit more "<<total-amount<<":";
  cin>>amount2;
  if(amount2<0)
    {    goto b;
    }
  amount=amount+amount2;

  if(amount<total)
  { clrscr();
    cout<<"\n\n\nThe amount is not enough, Please collect what you deposited and leave";
    getch();
    mainmenu();
    mainmenu_tasks();
  }
  else if(amount>total)
  {clrscr();
  cout<<"\n\n\n\n\n\n\t\t\tYour balance:"<<amount-total;
  getch();
  }

  else if(amount==total)
  {clrscr();
  cout<<"Thank you ";
  }
  }
  else if(amount>total)
  {clrscr();
  cout<<"\n\n\n\n\n\n\t\t\tYour balance:"<<amount-total;
  getch();
  }
  else
  {
  cout<<"Sorry you can't Avail the service";
  getch();
  }
  clrscr();
  cout<<"Thank you";
  cout<<"\n\n\n\n\n\t\t\t\Please ViSiT AGain";
  }
void cars::password()
{
 clrscr();
 s1.colours(0);
 char user[]="admin",pass[]="admin";
 char user1[12],pass1[12];

 for(int i=0;i<7;i++)
  {
  gotoxy(26,9+i);
  cprintf("|");
  }
  for(i=0;i<7;i++)
  {
  gotoxy(48,9+i);
  cprintf("|");
  }
  for( i=0;i<22;i++)
  {
  gotoxy(26+i,9);
  cprintf("--");
  }
  for(i=0;i<22;i++)
  {
  gotoxy(26+i,16);
  cprintf("--");
  }
  textcolor(130);
  gotoxy(28,10);
  cprintf("User Authentication");
  textcolor(3);
  gotoxy(29,13);
  cprintf("Username:");
  gotoxy(29,14);
  cprintf("Password:");
  gotoxy(38,13);
  cin>>user1;
  gotoxy(38,14);
  cin>>pass1;

  if(strcmp(user,user1)==0 && strcmp(pass,pass1)==0)
  {
   clrscr();
   gotoxy(30,12);
   cprintf("LOGIN SUCCESSFUL\n");
   sleep(1);
  }
  else
  {
   clrscr();
   gotoxy(30,12);
   cprintf("The password that you're entered is incorrect !\n");
   sleep(1);
   exit(0);
  }
   getch();
  }

void cars::help()
{
    clrscr();
    s1.colours(0);
    gotoxy(22,4);
    cprintf("******Help Menu******");
    gotoxy(1,8);
    cprintf(" For File menu:# press [f/F]: To register and Edit cars.");
    gotoxy(1,10);
    cprintf(" For Vehicles menu:# press [v/V]: To display all the vehicles.");
    gotoxy(1,18);
    cprintf(" To Exit:# [e/E]");
    gotoxy(1,12);
    cprintf(" For Service :# press [s/S] :For Services ");
    gotoxy(1,14);
    cprintf(" For Help press:# press [h/H] : Help menu ");
    gotoxy(1,16);
    cprintf(" For Transaction press:# [t/T] :To buy a Car");
    gotoxy(1,18);
 }

 int cars::check_id()       // for generating unique id
  {
       fstream fp;
       int k,j=1;
       fp.open("Added_record.dat",ios::in|ios::app);
       k=0;

       while(fp.read((char *)&s1,sizeof(s1)))
       {
	j=id;
	k++;
       }
       fp.close();
       if(k!=0)
       j=j+1;

       return j;
  }





