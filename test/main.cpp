#include <iostream>
#ifdef _MSC_VER
#include <windows.h>
#else
#include <dlfcn.h>
#endif
typedef unsigned int(*pImageSimilarity)(const char* sample_path, const char* refer_path, int rank);
using namespace std;

//TODO：write manual
void Usage() {

}

int main(int argc, char* argv[]) {
	if (argc < 3) {
		cerr << "param error!" << endl;
		Usage();
		return -1;
	}
#ifdef _MSC_VER
	HMODULE hLib =  LoadLibraryA("imagecompare.dll");
	pImageSimilarity func = (pImageSimilarity)GetProcAddress(hLib, "ImageSimilarity");
#else
	void* hLib  = dlopen("./libimagecompare.so", RTLD_LAZY);
	pImageSimilarity func = (pImageSimilarity)dlsym(hLib, "ImageSimilarity");
#endif
	if (!func) {
		cerr << "Get function address Error!" << endl;
		return -1;
	}
	unsigned int ret = func(argv[1], argv[2], 16);
	cout << argv[1] << endl;
	cout << argv[2] << endl;
	cout << "相似度：" << (ret * 1.0) / 1000  << "%"<< endl;
	//TODO: release hLib
	return 0;
}