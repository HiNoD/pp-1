#pragma once
#include <memory>
class CalculatingData
{
public:
	CalculatingData(unsigned int numOfDots, unsigned int inCircleDotsCounter);
	unsigned int GetTotalNumOfDots();
	unsigned int* GetTotalNumOfDotsPtr();
	unsigned int GetInCircleNumOfDots();
	unsigned int GetDotsAmmountToCreate();
	unsigned int* GetInCircleNumOfDotsPtr();
	~CalculatingData();
private:
	std::shared_ptr<unsigned int> m_numOfDotsPtr;
	std::shared_ptr<unsigned int> m_numOfDotsInCirclePtr;
	std::shared_ptr<unsigned int> m_dotsAmountToCreate;
};
