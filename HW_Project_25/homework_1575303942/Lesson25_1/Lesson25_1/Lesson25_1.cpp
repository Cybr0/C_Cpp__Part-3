#include <iostream>
#include "LinkedArray.h"
#include "Array.h"

namespace one {
	void foo() {
		std::cout << "Foo one\n";
	}
}
namespace two {
	void foo() {
		std::cout << "Foo two\n";
	}
}
namespace one {
	void foo2() {
		std::cout << "Foo one 2\n";
	}
}
namespace {
	void foo() {
		std::cout << "Foo noname\n";
	}
}
namespace {
	void foo2() {
		std::cout << "Foo noname 2\n";
	}
}

int main()
{
	linear::Array arr;
	arr.push_back(0);
}
