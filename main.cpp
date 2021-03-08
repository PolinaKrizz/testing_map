/****************************************************************************************************/
/* The application that checks if Ñ++ std::map container implementation complies with the standard. */
/* It is checking methods insert, erase and find. Use zero return code if test passes,              */
/* or non-zero  value to indicate test failure.                                                     */
/****************************************************************************************************/

#include <iostream>
#include <map>

// insert non-existent element
// element must be inserted
int test_insert_new_elem_method_insert()
{
	std::map<int, int> mp;
	int size_1 = mp.size();
	mp.insert(std::make_pair(0, 1));
	int size_2 = mp.size();
	return (size_1 != size_2);		
}

// insert an existing item
// element must not be inserted
int test_insert_existing_elem_method_insert()
{
	std::map<int, int> mp = { {0,1} };
	int size_1 = mp.size();
	mp.insert(std::make_pair(0, 1));
	int size_2 = mp.size();
	return (size_1 == size_2);		
}

// insert item with existing key value
// element must not be inserted
int test_insert_existing_key_method_insert()
{
	std::map<int, int> mp = { {0,1} };
	int size_1 = mp.size();
	mp.insert(std::make_pair(0, 2));
	int size_2 = mp.size();
	return (size_1 == size_2);
}

// insert item with existing "value" value
// element must be inserted
int test_insert_existing_value_method_insert()
{
	std::map<int, int> mp = { {0,1} };
	int size_1 = mp.size();
	mp.insert(std::make_pair(1, 1));
	int size_2 = mp.size();
	return (size_1 != size_2);		
}

// insert item with double value in map<int,int>
// element must be inserted without fractional part
int test_insert_double_value_method_insert()
{
	std::map<int, int> mp;
	int size_1 = mp.size();
	mp.insert(std::make_pair(0, 0.5));
	int size_2 = mp.size();
	return (size_1 != size_2 && mp[0] == 0);
}

// insert item with double key in map<int,int>
// element must be inserted without fractional part
int test_insert_double_key_method_insert()
{
	std::map<int, int> mp;
	int size_1 = mp.size();
	mp.insert(std::make_pair(3.6, 3));
	int size_2 = mp.size();
	return (size_1 != size_2 && mp.begin()->first == 3);
}

// insert item with char value in map<int,int>
// instead of a character, the code of this character 
// from ASCII will be inserted into the map
int test_insert_char_value_method_insert()
{
	std::map<int, int> mp;
	int size_1 = mp.size();
	mp.insert(std::make_pair(0, '0'));
	int size_2 = mp.size();
	return (size_1 != size_2 && mp[0] == 48);
}


// insert non-existent element
// element must be inserted
int test_insert_new_elem_operator()
{
	std::map<int, int> mp;
	int size_1 = mp.size();
	mp[0] = 1;
	int size_2 = mp.size();
	return (size_1 != size_2);
}

// insert an existing item
// element must not be inserted
int test_insert_existing_elem_operator()
{
	std::map<int, int> mp = { {0,1} };
	int size_1 = mp.size();
	mp[0] = 1;
	int size_2 = mp.size();
	return (size_1 == size_2);
}

// insert item with existing key value
// element must not be inserted
int test_insert_existing_key_operator()
{
	std::map<int, int> mp = { {0,1} };
	int size_1 = mp.size();
	mp[0] = 2;
	int size_2 = mp.size();
	return (size_1 == size_2);
}

// insert item with existing "value" value
// element must be inserted
int test_insert_existing_value_operator()
{
	std::map<int, int> mp = { {0,1} };
	int size_1 = mp.size();
	mp[1] = 1;
	int size_2 = mp.size();
	return (size_1 != size_2);
}

// insert item with double value in map<int,int>
// element must be inserted without fractional part
int test_insert_double_value_operator()
{
	std::map<int, int> mp;
	int size_1 = mp.size();
	mp[0] = 0.91;
	int size_2 = mp.size();
	return (size_1 != size_2 && mp[0] == 0);
}

// insert item with double key in map<int,int>
// element must be inserted without fractional part
int test_insert_double_key_operator()
{
	std::map<int, int> mp;
	int size_1 = mp.size();
	mp[3.6] = 3;
	int size_2 = mp.size();
	return (size_1 != size_2 && mp.begin()->first == 3);
}

// insert item with char value in map<int,int>
// instead of a character, the code of this character 
// from ASCII will be inserted into the map
int test_insert_char_value_operator()
{
	std::map<int, int> mp;
	int size_1 = mp.size();
	mp[0] = '0';
	int size_2 = mp.size();
	return (size_1 != size_2 && mp[0] == 48);
}


// erase existing item
// item must be erased
int test_erase_existing_elem()					
{
	std::map<int, int> mp = { {0,1}, {2,2}, {3,2} };
	int size_1 = mp.size();
	mp.erase(0);
	int size_2 = mp.size();
	return (size_1 != size_2);		
}

// erase element with index greater
// item must not be erased
int test_erase_index_greater()					
{
	std::map<int, int> mp = { {0,1}, {2,2}, {3,2} };
	int size_1 = mp.size();
	mp.erase(4);
	int size_2 = mp.size();
	return (size_1 == size_2);		
}

// erase element with negative index
// item must not be erased
int test_erase_negative_index()					
{
	std::map<int, int> mp = { {0,1}, {2,2}, {3,2} };
	int size_1 = mp.size();
	mp.erase(-1);
	int size_2 = mp.size();
	return (size_1 == size_2);		
}


// find by existing key
// item must be found
int test_find_existing_key()					
{
	std::map<int, int> mp = { {0,1}, {2,2}, {3,2} };
	return mp.find(3) != mp.end();	
}

// find by non-existent key
// item must be found
int test_find_nonexistent_key()
{
	std::map<int, int> mp = { {0,1}, {2,2}, {3,2} };
	return mp.find(4) == mp.end();	
}

int test_insert() 
{
	int rc = 0;

	if (test_insert_new_elem_method_insert()) {
		std::cout << "Test insert new element whit method insert\t\t\t passed\n";
	}
	else {
		std::cout << "Test insert new element whit method insert\t\t\t failed\n";
		rc = 1;
	}

	if (test_insert_existing_elem_method_insert()) {
		std::cout << "Test insert existing element whit method insert\t\t\t passed\n";
	}
	else {
		std::cout << "Test insert existing element whit method insert\t\t\t failed\n";
		rc = 2;
	}

	if (test_insert_existing_key_method_insert()) {
		std::cout << "Test insert existing key whit method insert\t\t\t passed\n";
	}
	else {
		std::cout << "Test insert existing key whit method insert\t\t\t failed\n";
		rc = 3;
	}

	if (test_insert_existing_value_method_insert()) {
		std::cout << "Test insert existing value whit method insert\t\t\t passed\n";
	}
	else {
		std::cout << "Test insert existing value whit method insert\t\t\t failed\n";
		rc = 4;
	}

	if (test_insert_double_value_method_insert()) {
		std::cout << "Test insert double value in map<int,int> with method insert\t passed\n";
	}
	else {
		std::cout << "Test insert double value in map<int,int> with method insert\t failed\n";
		rc = 5;
	}

	if (test_insert_double_key_method_insert()) {
		std::cout << "Test insert double key in map<int,int> with method insert\t passed\n";
	}
	else {
		std::cout << "Test insert double key in map<int,int> with method insert\t failed\n";
		rc = 6;
	}

	if (test_insert_char_value_method_insert()) {
		std::cout << "Test insert char value in map<int,int> with method insert\t passed\n";
	}
	else {
		std::cout << "Test insert char value in map<int,int> with method insert\t failed\n";
		rc = 7;
	}

	if (test_insert_new_elem_operator()) {
		std::cout << "Test insert new element with operator[]\t\t\t\t passed\n";
	}
	else {
		std::cout << "Test insert new element with operator[]\t\t\t\t failed\n";
		rc = 8;
	}

	if (test_insert_existing_elem_operator()) {
		std::cout << "Test insert existing element with operator[]\t\t\t passed\n";
	}
	else {
		std::cout << "Test insert existing element with operator[]\t\t\t failed\n";
		rc = 9;
	}

	if (test_insert_existing_key_operator()) {
		std::cout << "Test insert existing key with operator[]\t\t\t passed\n";
	}
	else {
		std::cout << "Test insert existing key with operator[]\t\t\t failed\n";
		rc = 10;
	}

	if (test_insert_existing_value_operator()) {
		std::cout << "Test insert existing value with operator[]\t\t\t passed\n";
	}
	else {
		std::cout << "Test insert existing value with operator[]\t\t\t failed\n";
		rc = 11;
	}

	if (test_insert_double_value_operator()) {
		std::cout << "Test insert double value in map<int,int> with operator[]\t passed\n";
	}
	else {
		std::cout << "Test insert double value in map<int,int> with operator[]\t failed\n";
		rc = 12;
	}

	if (test_insert_double_key_operator()) {
		std::cout << "Test insert double key in map<int,int> with operator[]\t\t passed\n";
	}
	else {
		std::cout << "Test insert double key in map<int,int> with operator[]\t\t failed\n";
		rc = 13;
	}

	if (test_insert_char_value_operator()) {
		std::cout << "Test insert char value in map<int,int> with operator[]\t\t passed\n";
	}
	else {
		std::cout << "Test insert char value in map<int,int> with operator[]\t\t failed\n";
		rc = 14;
	}

	return rc;
}

int test_erase() 
{
	int rc = 0;

	if (test_erase_existing_elem()) {
		std::cout << "Test erase existing element\t\t\t\t\t passed\n";
	}
	else {
		std::cout << "Test erase existing element\t\t\t\t\t failed\n";
		rc = 1;
	}

	if (test_erase_index_greater()) {
		std::cout << "Test erase index greater\t\t\t\t\t passed\n";
	}
	else {
		std::cout << "Test erase index greater\t\t\t\t\t failed\n";
		rc = 2;
	}

	if (test_erase_negative_index()) {
		std::cout << "Test erase negative index\t\t\t\t\t passed\n";
	}
	else {
		std::cout << "Test erase negative index\t\t\t\t\t failed\n";
		rc = 3;
	}

	return rc;
}

int test_find() 
{
	int rc = 0;

	if (test_find_existing_key()) {
		std::cout << "Test find existing key\t\t\t\t\t\t passed\n";
	}
	else {
		std::cout << "Test find existing key\t\t\t\t\t\t failed\n";
		rc = 1;
	}

	if (test_find_nonexistent_key()) {
		std::cout << "Test find non-existing key\t\t\t\t\t passed\n";
	}
	else {
		std::cout << "Test find non-existing key\t\t\t\t\t failed\n";
		rc = 2;
	}

	return rc;
}

int main()
{
	if (test_insert()) {		
		return 1;
	}
	if (test_erase()) {		
		return 2;
	}
	if (test_find()) {		
		return 3;
	}
	return 0;
}


// the following tests show attempts to insert a string into map <int, int>
// these tests are commented out because the compiler does not allow 
// converting the string to int in any way
// the compiler throws an error

//int test_insert_new_elem_method_insert_notint()
//{
//	std::map<int, int> mp;
//	int size_1 = mp.size();
//	mp.insert(std::make_pair(0, "0"));
//	int size_2 = mp.size();
//	return (size_1 != size_2);
//}
//
//int test_insert_new_elem_method_insert_notint()
//{
//	std::map<int, int> mp;
//	int size_1 = mp.size();
//	mp.insert(std::make_pair("0", 5));
//	int size_2 = mp.size();
//	return (size_1 != size_2);
//}
//
//int test_insert_new_elem_operator()
//{
//	std::map<int, int> mp;
//	int size_1 = mp.size();
//	mp["1"] = 1;
//	int size_2 = mp.size();
//	return (size_1 != size_2);
//}
//
//int test_insert_new_elem_operator()
//{
//	std::map<int, int> mp;
//	int size_1 = mp.size();
//	mp[0] = "0";
//	int size_2 = mp.size();
//	return (size_1 != size_2);
//}