/****************************************************************************
 Copyright (c) 2010 cocos2d-x.org
 Copyright (c) 2010 Максим Аксенов
 Copyright (c) 2017-2018 Xiamen Yaji Software Co., Ltd.
 
 Permission is hereby granted, free of charge, to any person obtaining a copy
 of this software and associated documentation files (the "Software"), to deal
 in the Software without restriction, including without limitation the rights
 to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
 copies of the Software, and to permit persons to whom the Software is
 furnished to do so, subject to the following conditions:
 
 The above copyright notice and this permission notice shall be included in
 all copies or substantial portions of the Software.
 
 THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
 IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
 FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
 AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
 LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
 OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN
 THE SOFTWARE.
 ****************************************************************************/

#ifndef __SAXPARSER_H__
#define __SAXPARSER_H__

#include <string>

namespace saxparser
{
    typedef unsigned char XML_CHAR;

    class SAXDelegator
    {
    public:
        virtual ~SAXDelegator() {}
        virtual void startElement(void *ctx, const char *name, const char **atts) = 0;
        virtual void endElement(void *ctx, const char *name, size_t len) = 0;
        virtual void startAttribute(void *ctx, const char *name, size_t nameLen, const char *value, size_t valueLen) = 0;
        virtual void endAttribute(void *ctx) = 0;
        virtual void textHandler(void *ctx, const char *s, size_t len) = 0;
        virtual void cdataHandler(void *ctx, const char *s, size_t len) = 0;
    };

    class SAXParser
    {
        SAXDelegator *_delegator;

    public:
        SAXParser();
        ~SAXParser();
        bool init(const char *encoding);
        bool parse(const char *xmlData, size_t dataLength);
        bool parseIntrusive(char *xmlData, size_t dataLength);

        void setDelegator(SAXDelegator *delegator);
        static void startElement(void *ctx, const XML_CHAR *name, const XML_CHAR **atts);
        static void endElement(void *ctx, const XML_CHAR *name, size_t len);
        static void textHandler(void *ctx, const XML_CHAR *text, size_t len);
        static void startAttribute(void *ctx, const XML_CHAR *name, size_t nameLen, const XML_CHAR *value, size_t valueLen);
        static void endAttribute(void *ctx);
        static void cdataHandler(void *ctx, const XML_CHAR *cdata, size_t len);
    };

} // namespace saxparser

#endif //__SAXPARSER_H__