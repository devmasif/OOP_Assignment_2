#include "pch.h"
#include "D:\Assignment2_OOP\A2_oop\A2_oop\Source.cpp"
#include "D:\Assignment2_OOP\A2_oop\A2_oop\String.h"
#include "D:\Assignment2_OOP\A2_oop\A2_oop\String.cpp"

// QUESTION 1
// add_Container TEST
TEST(Shop, add_Container) {
	Shop obj;
	char name1[5] = "PENS";
	char name2[6] = "RULER";
	char name3[7] = "BINDER";
	obj.add_Container(name1, 12);
	obj.add_Container(name2, 7);
	obj.add_Container(name3, 20);
	char* test = obj.start->link->name;
	EXPECT_EQ(0, strcmp(name2, test));
	EXPECT_EQ(NULL, (obj.start->link->link->link));
}
//CopyConstructor
TEST(Shop, copyConstructor) {

	Shop obj;
	char name1[5] = "PENS";
	char name2[6] = "RULER";
	char name3[7] = "BINDER";
	obj.add_Container(name1, 12);
	obj.add_Container(name2, 7);
	obj.add_Container(name3, 20);

	Shop obj2(obj);

	char* test = obj2.start->link->name;
	EXPECT_EQ(0, strcmp(name2, test));
	EXPECT_EQ(NULL, (obj2.start->link->link->link));
}
// PRINT_SHOP TEST
TEST(Shop, print_Shop) {
	Shop obj;

	testing::internal::CaptureStdout();
	obj.print_Shop();
	std::string output0 = testing::internal::GetCapturedStdout();
	std::string answer0 = "";

	EXPECT_EQ(1, output0 == answer0);

	char name1[5] = "PENS";
	char name2[6] = "RULER";
	char name3[7] = "BINDER";
	obj.add_Container(name1, 12);
	obj.add_Container(name2, 7);
	obj.add_Container(name3, 20);

	testing::internal::CaptureStdout();
	obj.print_Shop();
	std::string output = testing::internal::GetCapturedStdout();
	std::string answer = "PENS-12\nRULER-7\nBINDER-20\n";

	EXPECT_EQ(1, output == answer);
}
// DELETE_CHAIN TEST
TEST(Shop, delete_Chain) {
	Shop obj;
	char name1[5] = "PENS";
	obj.add_Container(name1, 12);
	obj.delete_Chain(12);
	EXPECT_EQ(NULL, (obj.start));
	char name2[6] = "RULER";
	char name3[7] = "BINDER";
	obj.add_Container(name1, 12);
	obj.add_Container(name2, 7);
	obj.add_Container(name3, 20);
	obj.delete_Chain(7);
	EXPECT_EQ(0, strcmp(name3, (obj.start->link->name)));
	EXPECT_EQ(NULL, obj.start->link->link);
	char name4[5] = "TAPE";
	obj.add_Container(name4, 5);
	EXPECT_EQ(0, strcmp(name4, (obj.start->link->link->name)));

}
// SORT_CHAIN TEST
TEST(Shop, Sort_Chain) {
	Shop obj;
	char name1[5] = "PENS";
	char name2[6] = "RULER";
	char name3[7] = "BINDER";
	obj.add_Container(name1, 12);
	obj.add_Container(name2, 7);
	obj.add_Container(name3, 20);
	obj.Sort_Chain();

	EXPECT_EQ(0, strcmp(name2, (obj.start->name)));
	EXPECT_EQ(0, strcmp(name1, (obj.start->link->name)));
	EXPECT_EQ(0, strcmp(name3, (obj.start->link->link->name)));

	char name4[5] = "TAPE";
	obj.add_Container(name4, 5);

	obj.Sort_Chain();
	EXPECT_EQ(0, strcmp(name2, (obj.start->link->name)));
	EXPECT_EQ(0, strcmp(name1, (obj.start->link->link->name)));
	EXPECT_EQ(0, strcmp(name3, (obj.start->link->link->link->name)));
	EXPECT_EQ(0, strcmp(name4, (obj.start->name)));

}
TEST(Shop, update_name_at_containernumber) {
	Shop obj;
	char name1[5] = "PENS";
	char name2[6] = "RULER";
	char name3[7] = "BINDER";
	obj.add_Container(name1, 12);
	obj.add_Container(name2, 7);
	obj.add_Container(name3, 20);

	obj.update_name_at_containerNumber(7, "PROTRACTOR");
	obj.update_name_at_containerNumber(12, "HIGHLIGHTER");
	obj.update_name_at_containerNumber(20, "STAPLER");

	EXPECT_EQ(0, strcmp(obj.start->name, "HIGHLIGHTER"));
	EXPECT_EQ(0, strcmp(obj.start->link->name, "PROTRACTOR"));
	EXPECT_EQ(0, strcmp(obj.start->link->link->name, "STAPLER"));

}
TEST(Shop, remove_Duplicate) {
	Shop obj;
	char name1[5] = "PENS";
	char name2[6] = "RULER";
	char name3[7] = "BINDER";
	obj.add_Container(name1, 12);
	obj.add_Container(name2, 7);
	obj.add_Container(name3, 20);
	obj.add_Container(name3, 20);
	obj.add_Container(name1, 12);
	obj.remove_Duplicate();

	char* test = obj.start->link->name;
	EXPECT_EQ(0, strcmp(name2, test));
	EXPECT_EQ(NULL, (obj.start->link->link->link));

	Shop obj1;
	obj1.add_Container(name1, 12);
	obj1.add_Container(name1, 12);
	obj1.add_Container(name1, 12);
	obj1.remove_Duplicate();
	EXPECT_EQ(0, strcmp(name1, obj1.start->name));
}
// FIND_CONTAINER TEST
TEST(Shop, findContainer) {
	Shop obj;
	char name1[5] = "PENS";
	char name2[6] = "RULER";
	char name3[7] = "BINDER";
	obj.add_Container(name1, 12);
	obj.add_Container(name2, 7);
	obj.add_Container(name2, 7);
	obj.add_Container(name3, 20);

	testing::internal::CaptureStdout();
	obj.findContainer(7);
	std::string output = testing::internal::GetCapturedStdout();
	std::string answer = "RULER\n";

	EXPECT_EQ(1, output == answer);

	testing::internal::CaptureStdout();
	obj.findContainer(8);
	std::string output2 = testing::internal::GetCapturedStdout();
	std::string answer2 = "";

	EXPECT_EQ(1, output2 == answer2);

}
//FIND_CONTAINER RANGE TEST
TEST(Shop, findContainer2) {

	Shop obj;
	char name1[5] = "PENS";
	char name2[6] = "RULER";
	char name3[7] = "BINDER";
	char name4[8] = "STAPLER";
	char name5[7] = "ERASER";
	obj.add_Container(name1, 12);
	obj.add_Container(name2, 7);
	obj.add_Container(name3, 20);
	obj.add_Container(name4, 30);
	obj.add_Container(name5, 24);

	testing::internal::CaptureStdout();
	obj.findContainer(12, 25); //12 and 25 are both Included in the Range
	std::string output = testing::internal::GetCapturedStdout();
	std::string answer = "PENS\nBINDER\nERASER\n";

	EXPECT_EQ(1, output == answer);

}


//QUESTION 2
TEST(String, Constructors) {
	char s[] = "OOP-A02";

	//String str0;
	//ASSERT_STREQ(NULL, str0.getdata());

	String str(s);
	ASSERT_STREQ("OOP-A02", str.getdata());

	String str1(5);
	ASSERT_STREQ("", str1.getdata());

	String str2(str);
	ASSERT_STREQ(str2.getdata(), str.getdata());
	ASSERT_STRNE(str2.getdata(), str1.getdata());

}
//TEST(String, squareBrackets) {
//
//	char s[] = "Hello World!";
//	String str(s);
//
//	ASSERT_EQ('o', str[4]);
//	ASSERT_EQ('\0', str[12]);
//
//	String str1(str);
//	ASSERT_EQ('H', str1[0]);
//	ASSERT_EQ('!', str1[-1]);
//
//	ASSERT_EQ('H', str1[-12]);
//
//
//}
//TEST(String, addition) {
//	char st[] = "Assignment02";
//	String str(st);
//	char t1[] = "Done";
//	String str1(str);
//	char t3 = 'g';
//
//	str + t1;
//	ASSERT_STREQ(str.getdata(), "Assignment02Done");
//
//	str + str1;
//	ASSERT_STREQ(str.getdata(), "Assignment02DoneAssignment02");
//
//	str + t3;
//	ASSERT_STREQ(str.getdata(), "Assignment02DoneAssignment02g");
//
//}
//TEST(String, subtraction) {
//	char st[] = " Fast Spring 2024 ";
//	String str(st);
//
//	str - ' ';
//	ASSERT_STREQ(str.getdata(), "FastSpring2023");
//
//	char t2[] = "20";
//	str - t2;
//	ASSERT_STREQ(str.getdata(), "FastSpring23");
//
//	String str1("Spring");
//	str - str1;
//	ASSERT_STREQ(str.getdata(), "Fast23");
//
//}
//TEST(String, circularBrackets) {
//	char st[] = "OOP-Assignment02";
//	String str(st);
//	ASSERT_EQ(0, str('O'));
//	ASSERT_EQ(2, str('P'));
//	ASSERT_EQ(5, str('s'));
//	ASSERT_EQ(14, str('0'));
//	ASSERT_EQ(-1, str('F'));
//
//	char st1[] = "Spring 2024";
//	char t[] = "2024";
//	String test(t);
//	String str1(st1);
//	ASSERT_EQ(2, str1("ring"));
//	ASSERT_EQ(7, str1(test));
//}
//TEST(String, lengthofString) {
//	char st[] = " Fast Spring 2024 ";
//	String str(st);
//
//	EXPECT_EQ((int)str, 18);
//
//	String str2(str);
//	str2 + "New";
//
//	EXPECT_EQ((int)str2, 21);
//
//	str2 - "2024";
//
//	EXPECT_EQ((int)str2, 17);
//}
//TEST(String, isEmpty) {
//	char st[] = "OOP-A02";
//	String str(st);
//	ASSERT_EQ(false, !str);
//	ASSERT_EQ(7, (int)str);
//
//	String str1(5);
//	ASSERT_EQ(true, !str1);
//	ASSERT_EQ(0, (int)str1);
//}
//TEST(String, isEqual) {
//	char st[] = "OOP-Assignment02";
//	String str(st);
//
//	char t1[] = "OOP", t2[] = "Assignment02", t3[] = "oop assignment02", t4[] = "OOP-Assignment02";
//	ASSERT_EQ(false, str == t1);
//	ASSERT_EQ(false, str == t2);
//	ASSERT_EQ(false, str == t3);
//	ASSERT_EQ(true, str == t4);
//
//	char st1[] = "Spring 2024";
//	String str1(st1);
//
//	char t11[] = "spring 2024", t12[] = "sprIng 2022";
//	ASSERT_EQ(false, str1 == t11);
//	ASSERT_EQ(false, str1 == t12);
//	ASSERT_EQ(true, str1 == st1);
//	ASSERT_EQ(true, str1 == "Spring 2024");
//}
//TEST(String, equalOverloaded) {
//	char st[] = "OOP-Assignment02";
//	String str(st);
//
//	str = "hello world";
//	ASSERT_STREQ(str.getdata(), "hello world");
//	ASSERT_EQ(11, (int)str);
//
//	String str1("OOP-Assignment02");
//	str = str1;
//	ASSERT_STREQ(str.getdata(), "OOP-Assignment02");
//	ASSERT_EQ(16, (int)str);
//
//}
//TEST(String, inputAndOutput) {
//
//	char st[] = "OOP-Assignment02";
//	String str(st);
//	String str2;
//
//	testing::internal::CaptureStdout();
//	cout << str << str2;
//	std::string output = testing::internal::GetCapturedStdout();
//	std::string answer = "OOP-Assignment02\n";
//
//	EXPECT_EQ(1, output == answer);
//
//	cin >> str2;
//	cout << str2;
//
//}