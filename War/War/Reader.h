#pragma once
#include "stdafx.h"
#include "State.h"
#include "Cell.h"

using namespace std;
using namespace CellInfo;

const int shift = 48;

class Reader
{
public:

	Reader(const string & fileName)
	{
		m_stream = ifstream(fileName);
	}

	long ReadShellCost()
	{
		string readLine;
		getline(m_stream, readLine);
		return std::stol(readLine, std::string::size_type());
	}

	Territory ReadState()
	{
		Territory result;
		string readLine;
		Cell currentCell;

		getline(m_stream, readLine);

		while (!readLine.empty())
		{
			result.AddLine();
			stringstream stream(readLine);
			char currentSymbol;
			while (stream >> currentSymbol)
			{
				int convertedChar = (int)currentSymbol - shift;
				switch (convertedChar)
				{
				case 0:
					currentCell.SetType(EMPTY);
					break;
				case 1:
					currentCell.SetType(HOUSE);
					break;
				case 2:
					currentCell.SetType(FACTORY);
					break;
				case 3:
					currentCell.SetType(DESTROYED);
					break;
				default:
					break;
				}
				result.AddCell(currentCell);
			}

			if (m_stream.eof())
			{
				break;
			}

			getline(m_stream, readLine);
		}
		result.SetTerritoryCost();
		return result;
	}

	CState ParseState()
	{
		long shellCost = ReadShellCost();
		Territory territory = ReadState();
		CState result(territory, shellCost);
		return result;
	}

private:
	ifstream m_stream;
};

