// Copyright 2017-2018 zzu_softboy <zzu_softboy@163.com>
//
// THIS SOFTWARE IS PROVIDED BY THE AUTHOR ``AS IS'' AND ANY EXPRESS OR
// IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED WARRANTIES
// OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE DISCLAIMED.
// IN NO EVENT SHALL THE AUTHOR BE LIABLE FOR ANY DIRECT, INDIRECT,
// INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT
// NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE,
// DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY
// THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT
// (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF
// THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
//
// Created by softboy on 2017/08/14.

#include "php/sapi/embed/php_embed.h"
#include "gtest/gtest.h"
#include "zapi/ds/ArrayVariant.h"
#include "zapi/ds/ArrayItemProxy.h"
#include "zapi/ds/NumericVariant.h"
#include "zapi/ds/StringVariant.h"

using zapi::ds::ArrayVariant;
using zapi::ds::Variant;
using zapi::ds::NumericVariant;
using zapi::ds::StringVariant;

TEST(ArrayVariantTest, testConstructor)
{
   ArrayVariant array;
   ASSERT_TRUE(array.isNull());
   ASSERT_TRUE(array.isEmpty());
   ASSERT_TRUE(array.isArray());
   
}

TEST(ArrayVariantTest, testAppend)
{
   ArrayVariant array;
   ASSERT_TRUE(array.isNull());
   ASSERT_TRUE(array.isEmpty());
   array.append(1);
   ASSERT_FALSE(array.isNull());
   ASSERT_FALSE(array.isEmpty());
   ASSERT_EQ(array.getSize(), 1);
   array.append("zapi");
   ASSERT_EQ(array.getSize(), 2);
   NumericVariant num = array.getValue(0);
   //std::cout << num.toLong() << std::endl;
   StringVariant str = array.getValue(1);
   //std::cout << str << std::endl
}
