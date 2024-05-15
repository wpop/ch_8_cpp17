#include <iostream>

[[noreturn]] void func() {
	std::cout << "[[noreturn]] void func*()" << std::endl;
	std::abort();
}

// compile with warning
[[depricated]] int very_old_func()
{
	 return 72;
}

// turns off warning if brake mossed
int switchFunc(int value) {
	int result = 0;
	switch(value) {
		case 0:
			result = 10;
			[[fallthrough]];
		case 1:
			result += 15;
			break;
		case 3:
			result = 72;
			[[fallthrough]];
		case 4:
			result += 15;
			break;
		default:
			result = 777;
	}
	return result;
}

// ask compiler producing a warning if call the func without saving the result
[[nodiscard]]
int funcNoDiscard() {
	return 743;
}

// should make code optimization declaring val as an atomic value
void print_(int* [[carries_dependency]] val)
{
	std::cout<<"[[carries_dependency]]"<<std::endl;
	std::cout << *val << std::endl;
}

template<typename SenderType>
struct WorkerAttributes
{
	u_int8_t a; // 1 byte pluss 3 padding
	[[no_unique_address]] SenderType sender;
	void run()
	{
		std::cout << "worker is running!" << std::endl;
		sender.send();
	}
};

// remove compiler warning if the variable declered but unused
void maybe_unused()
{
	[[maybe_unused]] int var = 3;
	std::cout<<"variable var is unused"<<std::endl;
}


// -------------------- Main --------------------
int main()
{
	std::cout << very_old_func() << std::endl;

	// int res = funcNoDiscard();
	funcNoDiscard();

	int variable = 126;
	int* ptr = &variable;
	print_(ptr);

	maybe_unused();
	
	return 0;
}