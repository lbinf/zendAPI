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
// Created by softboy on 2017/08/29.

#include "php/sapi/embed/php_embed.h"
#include "gtest/gtest.h"
#include "zapi/ds/Variant.h"

using zapi::ds::Variant;

TEST(VariantTest, testRefConstruct)
{
   zval var1;
   ZVAL_LONG(&var1, 123);
   ASSERT_EQ(Z_LVAL(var1), 123);
   Variant var(var1, true);
   ASSERT_EQ(Z_LVAL(var.getZval()), 123);
   var = 213;
   ASSERT_EQ(Z_LVAL(var.getZval()), 213);
   ASSERT_EQ(Z_LVAL_P(Z_REFVAL(var1)), 213);
   var = "zapi";
   ASSERT_STREQ(Z_STRVAL(var.getZval()), "zapi");
   ASSERT_STREQ(Z_STRVAL_P(Z_REFVAL(var1)), "zapi");
   var = Variant(2017);
   ASSERT_EQ(Z_LVAL(var.getZval()), 2017);
   ASSERT_EQ(Z_LVAL_P(Z_REFVAL(var1)), 2017);
   zval_dtor(&var1);
}

TEST(VariantTest, testCompareOperators)
{
   zval var1;
   ZVAL_LONG(&var1, 123);
   Variant variant1(var1, true);
   zval var2;
   ZVAL_LONG(&var2, 123);
   Variant variant2(var2, true);
   Variant variant3(123);
   ASSERT_TRUE(variant1 == variant2);
   ASSERT_TRUE(variant1 == variant3);
   zval_dtor(&var1);
   zval_dtor(&var2);
}