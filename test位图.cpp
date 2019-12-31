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

		//��1   ��whichλ��
		void set(size_t which)
		{
			if (which > _totalbiteSize)
				return;
			size_t index = (which >> 3);  //�ڼ����ֽ�
			size_t pos = which % 8;    //�ڼ�������λ
			_bst[index] |= (1 << pos);
			++_size;
		}
		//��0   whichλ��
		void reset(size_t which)
		{
			if (which > _totalbiteSize)
				return;
			size_t index = (which >> 3);  //�ڼ����ֽ�
			size_t pos = which % 8;    //�ڼ�������λ
			_bst[index] &= (~(1 << pos));
		}
		//����Ƿ�Ϊ1        whichλ��
		bool test(size_t which)
		{
			if (which > _totalbiteSize)
				return false;
			size_t index = (which >> 3);  //�ڼ����ֽ�
			size_t pos = which % 8;    //�ڼ�������λ
			//if (1 == (_bst[index] & (1 << pos)))
			//	return true;
			//return false;
			return 1==(_bst[index] & (1 << pos));
		}

		//ͳ���ֽ���
		size_t size()const
		{
			return _totalbiteSize;
		}
		//ͳ��Ϊ1���ֽڸ���
		size_t count()const
		{
			return _size;
		}
	private:
		vector<unsigned char> _bst;
		size_t _size;  //Ϊ1��biteλ����
		size_t _totalbiteSize;  //�ܵ��ֽ���
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
