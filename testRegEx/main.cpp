#include <iostream>
#include <string>
#include <regex>

int main() {
	std::string fnames[] = { "foo.txt", "bar.txt", "test", "a0.txt", "AAA.txt" };
	// �� C++ �� `\` �ᱻ��Ϊ�ַ����ڵ�ת�����Ϊʹ `\.` ��Ϊ������ʽ���ݽ�ȥ��Ч����Ҫ�� `\` ���ж���ת�壬�Ӷ��� `\\.`
	std::regex txt_regex("[a-z]+\\.txt");
	for (const auto &fname : fnames)
		std::cout << fname << ": " << std::regex_match(fname, txt_regex) << std::endl;

	std::regex base_regex("([a-z]+)\\.txt");
	std::smatch base_match;
	for (const auto &fname : fnames) {
		if (std::regex_match(fname, base_match, base_regex)) {
			// sub_match �ĵ�һ��Ԫ��ƥ�������ַ���
			// sub_match �ĵڶ���Ԫ��ƥ���˵�һ�����ű��ʽ
			if (base_match.size() == 2) {
				std::string base = base_match[1].str();
				std::cout << "sub-match[0]: " << base_match[0].str() << std::endl;
				std::cout << fname << " sub-match[1]: " << base << std::endl;
			}
		}
	}
	getchar();
}