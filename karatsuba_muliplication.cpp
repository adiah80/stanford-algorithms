#include<bits/stdc++.h>
using namespace std;

string str_add(string num1, string num2);
string str_sub(string num1, string num2);
string str_multiply(string num1, string num2);
string padd_right(string num, int padd_value);
string padd_left(string num, int padd_value);
string make_len_equal(string num1, string num2);
string cut_left(string num, int value);
string cut_right(string num, int value);
string remove_leading_zeros(string inp);
string str_kas_mul(string num1, string num2);

int main(){
	string num1;
	string num2;

	cout<<"Enter two numbers : "<<endl;
	
	cin>>num1>>num2;

	string product = str_kas_mul(num1, num2);
	
	cout<<product<<endl;
	return 0;
}

string str_add(string num1, string num2) {

	if (num1.length() > num2.length())
        swap(num1, num2);

    string str = "";

    int ln1 = num1.length();
	int ln2 = num2.length();

	reverse(num1.begin(), num1.end());
    reverse(num2.begin(), num2.end());

    int carry = 0;
    for (int i=0; i<ln1; i++) {
    	int sum = ((num1[i]-'0') + (num2[i]-'0') + carry);
    	str.push_back(sum % 10 + '0');
    	carry = sum/10;
    }


    for (int i=ln1; i<ln2; i++) {
    	int sum = ((num2[i] - '0') + carry);
    	str.push_back(sum%10 + '0');
    	carry = sum/10;
    }

    if (carry) 
    	str.push_back(carry + '0');

    reverse(str.begin(), str.end());

    return str;
}



string str_sub(string num1, string num2) {
	// Taking num2 > num1

	if (num1.length() > num2.length())
        swap(num1, num2);

    else if (num1.length	() == num2.length()) {
    	
    	int i=0;
    	while (num1[i] == num2[i])
    		i++;

    	if(num1[i] > num2[i])
    		swap(num1, num2);
    }

    string str = "";

    int ln1 = num1.length();
	int ln2 = num2.length();

	reverse(num1.begin(), num1.end());
    reverse(num2.begin(), num2.end());

    for (int i=0; i<ln1; i++) {
    	int diff = (num2[i]-'0') - (num1[i]-'0');

    	if (diff < 0) {
   	  		num2[i+1] = num2[i+1] - 1;
   	  		diff = diff + 10;
    	}
 		
 	   	str.push_back(diff + '0');
    }


    for (int i=ln1; i<ln2; i++)  
    	str.push_back(num2[i]);

    reverse(str.begin(), str.end());
    return str;
}



string str_multiply(string num1, string num2){

	string ret = "";

	int mul = (num1[0] - '0') * (num2[0] - '0');

	if (mul/10)
		ret.push_back(mul/10 + '0');

	ret.push_back(mul%10 + '0');

	return ret;
}



string padd_right(string num, int padd_value){
	// Pads the given string with padd_value zeros to right and returns it.
	// Eg : padd_right(123, 2) = 12300

	while(padd_value--)
		num.push_back('0');

	return num;
}


string padd_left(string num, int padd_value){
	// Pads the given string with padd_value zeros to left and returns it.
	// Eg : padd_right(123, 2) = 00123

	string num2(padd_value, '0');

	int len = num.length();
	for(int i=0; i<len; i++)
		num2.push_back(num[i]);

	return num2;
}


string make_len_equal(string num1, string num2){
	// Takes two numbers as input strings and pads the smaller one with zeros on the left to make their length equal. Returns the modified string.

	int ln1 = num1.length();
	int ln2 = num2.length();

	if( ln1 == ln2){
		printf("Error, numbers of equal length.\n");
	} else if (ln1 > ln2) {
		int diff = ln1 - ln2;
		num2 = padd_left(num2, diff);
		return num2;
	} else {
		int diff = ln2 - ln1;
		num1 = padd_left(num1, diff);
		return num1;
	}
}

string cut_left(string num, int value) {
	// Cuts leftmost 'value' values of given string and return them.
	string num2;

	for (int i=0; i<value; i++) {
		num2.push_back(num[i]);
	}

	return num2;
}

string cut_right(string num, int value){
	// Cuts rightmost 'value' values of given string and return them.
	string num2;
	int len = num.length();

	for (int i=value; i>0; i--) {
		num2.push_back(num[len - i]);
	}

	return num2;
}

string remove_leading_zeros(string inp){
	// Removes leading 0's from the string and returns it.

	int len = inp.length();
	string ret;

	int i=0;
	while(inp[i] == '0')
		i++;

	while(i < len){
		ret.push_back(inp[i]);
		i++;
	}

	return ret;
}


string str_kas_mul(string num1, string num2){
	// Implements Karatsuba multiplication on two input strings and returns their product as a string.

	printf("-----------------------------\n");
	cout<<"KARATSUBA HAPPENING : "<<num1<<", "<<num2<<endl;

	int ln1 = num1.length();
	int ln2 = num2.length();

	if (ln1 != ln2) {
		//printf("Failed, ln1 != ln2, ln1 = %d, ln2 = %d\n", ln1, ln2);
		if (ln1 > ln2) {
			num2 = make_len_equal(num1, num2);
			ln2 = num2.length();
		}
		if (ln1 < ln2) {
			num1 = make_len_equal(num1, num2);
			ln1 = num1.length();
		}
		//printf("Modified length of ln1, ln2 = %d, %d\n", ln1, ln2);
	}else {
		//printf("Passed, ln1 = ln2 = %d\n", ln1);
	}


	// BASE CASES
	if (ln1 == 1 && ln2 == 1) {
		string product_base = str_multiply(num1, num2);
		printf("Returned, product of %s and %s = %s [bc]\n", num1.c_str(), num2.c_str(), product_base.c_str());
		cout<<"-----------------------------"<<endl;
		return product_base;
 	}
 	// For num1
	string a = cut_left(num1, ln1 - ln1/2);
	string b = cut_right(num1, ln1/2);

	// For num2
	string c = cut_left(num2, ln2 - ln2/2);
	string d = cut_right(num2, ln2/2);

	printf("a,b,c,d = %s, %s, %s, %s\n", a.c_str(), b.c_str(), c.c_str(), d.c_str());

	// Calculating the products
	string ac = str_kas_mul(a,c);
	string bd = str_kas_mul(b,d);
	string bc_plus_ad = str_sub(str_sub(str_kas_mul(str_add(a, b), str_add(c, d)), ac), bd);

	//printf("VERIFY ------> %d, %d\n", ln1/2 * 2, ln1);
	string product = str_add(padd_right(ac, ln1/2 * 2), str_add(padd_right(bc_plus_ad, ln1/2), bd));

	product = remove_leading_zeros(product);

	printf("Karatsuba results [1,2,3] : %s, %s, %s\n", ac.c_str(), bc_plus_ad.c_str(), bd.c_str());
	printf("Returned, product of %s and %s = %s\n", num1.c_str(), num2.c_str(), product.c_str());
	cout<<"-----------------------------"<<endl;

	return product;
}