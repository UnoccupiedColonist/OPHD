// This is an open source non-commercial project. Dear PVS-Studio, please check it.
// PVS-Studio Static Code Analyzer for C, C++ and C#: http://www.viva64.com

#include "TextArea.h"

#include "../../Common.h"

#include <vector>

TextArea::TextArea() : mNumLines(0)
{}


TextArea::~TextArea()
{}


void TextArea::processString()
{
	mFormattedList.clear();

	if (width() < 1 || !fontSet() || text().empty())
		return;

	StringList tokenList = split_string(text().c_str(), ' ');
	
	size_t w = 0, i = 0;
	while (i < tokenList.size())
	{
		std::string line;
		while (w < width() && i < tokenList.size())
		{
			int tokenWidth = font().width(tokenList[i] + " ");
			w += tokenWidth;
			if (w >= width())
			{
				/**
				 * \todo	In some edge cases where the width of the TextArea is too
				 *			narrow for a single word/token, this will result in an infinite
				 *			loop. This edge case will need to be resolved either by splitting
				 *			the token that's too wide or by simply rendering it as is.
				 */
				//++i;
				break;
			}
			
			if (tokenList[i] == "\n")
			{
				++i;
				break;
			}
			line += (tokenList[i] + " ");
			++i;
		}
		w = 0;
		mFormattedList.push_back(line);
	}

	mNumLines = static_cast<size_t>(height() / font().height());
}


void TextArea::onSizeChanged()
{
	Control::onSizeChanged();
	processString();
}


void TextArea::onTextChanged()
{
	processString();
}


void TextArea::onFontChanged()
{
	processString();
}


void TextArea::update()
{
	draw();
}


void TextArea::draw()
{
	Renderer& r = Utility<Renderer>::get();

	if(highlight())
		r.drawBox(rect(), 255, 255, 255);

	for (size_t i = 0; i < mFormattedList.size() && i < mNumLines; ++i)
		r.drawText(font(), mFormattedList[i], positionX(), positionY() + (font().height() * i), 255, 255, 255);
}
