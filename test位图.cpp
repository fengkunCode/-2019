#define _CRT_SECURE_NO_WARNINGS 1
#include<iostream>
using namespace std;
#include<vector>


namespace bite{
	class bite{
	public:
		bite(size_t totalbit)
			:_bst((totalbit>>3)+1)
			, _size(0)
			, _totalbiteSize((totalbit >> 3) + 1)
		{}

		//置1   将which位置
		void set(size_t which)
		{
			if (which > _totalbiteSize)
				return;
			size_t index = (which >> 3);  //第几个字节
			size_t pos = which % 8;    //第几个比特位
			_bst[index] |= (1 << pos);
			++_size;
		}
		//置0   which位置
		void reset(size_t which)
		{
			if (which > _totalbiteSize)
				return;
			size_t index = (which >> 3);  //第几个字节
			size_t pos = which % 8;    //第几个比特位
			_bst[index] &= (~(1 << pos));
		}
		//检查是否为1        which位置
		bool test(size_t which)
		{
			if (which > _totalbiteSize)
				return false;
			size_t index = (which >> 3);  //第几个字节
			size_t pos = which % 8;    //第几个比特位
			//if (1 == (_bst[index] & (1 << pos)))
			//	return true;
			//return false;
			return 1==(_bst[index] & (1 << pos));
		}

		//统计字节数
		size_t size()const
		{
			return _totalbiteSize;
		}
		//统计为1的字节个数
		size_t count()const
		{
			return _size;
		}
	private:
		vector<unsigned char> _bst;
		size_t _size;  //为1的bite位个数
		size_t _totalbiteSize;  //总的字节数
	};

}

void test()
{

}

int main()
{

	test();
	return 0;
}
