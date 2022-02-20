#include <iostream>
#include <string>
#include <list>
#include <cppunit/TestCase.h>
#include <cppunit/TestFixture.h>
#include <cppunit/ui/text/TextTestRunner.h>
#include <cppunit/extensions/HelperMacros.h>
#include <cppunit/extensions/TestFactoryRegistry.h>
#include <cppunit/TestResult.h>
#include <cppunit/TestResultCollector.h>
#include <cppunit/TestRunner.h>
#include <cppunit/BriefTestProgressListener.h>
#include <cppunit/CompilerOutputter.h>
#include <cppunit/XmlOutputter.h>
#include <netinet/in.h>
#include "func.hpp"

using namespace CppUnit;
using namespace std;

class TestVerifyPassword : public CppUnit::TestFixture {
	    CPPUNIT_TEST_SUITE(TestVerifyPassword);
	    CPPUNIT_TEST(testToSix);
		CPPUNIT_TEST(testHasLowerCase);
		CPPUNIT_TEST(testHasUpperCase);
		CPPUNIT_TEST(testHasNumber);
		CPPUNIT_TEST(testHasSpecialChar);
        CPPUNIT_TEST_SUITE_END();
	public:
	    void setUp(void);
	    void tearDown(void);
	 
	protected:
	    void testToSix(void);
		void testHasLowerCase(void);
		void testHasUpperCase(void);
		void testHasNumber(void);
		void testHasSpecialChar(void);
	 
	private:
	 
	    rules *object;
};

void TestVerifyPassword::testToSix(void){

		CPPUNIT_ASSERT(0 == object->toSix("abcdef"));
		CPPUNIT_ASSERT(0 == object->toSix("abcdefghijklmn"));
		CPPUNIT_ASSERT(0 < object->toSix("abc"));

}


void TestVerifyPassword::testHasLowerCase(void){
	    
		CPPUNIT_ASSERT(1 == object->hasLowerCase("abc"));
		CPPUNIT_ASSERT(0 == object->hasLowerCase("ABC"));
		CPPUNIT_ASSERT(0 == object->hasLowerCase("123"));
}


void TestVerifyPassword::testHasUpperCase(void){
	    
		CPPUNIT_ASSERT(1 == object->hasUpperCase("ABC"));
		CPPUNIT_ASSERT(0 == object->hasUpperCase("abc"));
		CPPUNIT_ASSERT(0 == object->hasUpperCase("123"));
}

void TestVerifyPassword::testHasNumber(void){
	    
		CPPUNIT_ASSERT(1 == object->hasNumber("aB12"));
		CPPUNIT_ASSERT(0 == object->hasNumber("aB##"));
}

void TestVerifyPassword::testHasSpecialChar(void){
	    
		CPPUNIT_ASSERT(0 == object->hasSpecialChar("aB12"));
		CPPUNIT_ASSERT(1 == object->hasSpecialChar("aB##"));
}

	void TestVerifyPassword::setUp(void)
	{
	    object = new rules();

	}
	 
	void TestVerifyPassword::tearDown(void)
	{
	    delete object;

	}

    	CPPUNIT_TEST_SUITE_REGISTRATION( TestVerifyPassword );
	 
	int main(int argc, char* argv[])
	{

	    CPPUNIT_NS::TestResult testresult;
	 
	    CPPUNIT_NS::TestResultCollector collectedresults;
	    testresult.addListener (&collectedresults);
	 
	    CPPUNIT_NS::BriefTestProgressListener progress;
	    testresult.addListener (&progress);

	    CPPUNIT_NS::TestRunner testrunner;
	    testrunner.addTest (CPPUNIT_NS::TestFactoryRegistry::getRegistry().makeTest ());
	    testrunner.run(testresult);
	 
	    CPPUNIT_NS::CompilerOutputter compileroutputter(&collectedresults, std::cerr);
	    compileroutputter.write ();

	    return collectedresults.wasSuccessful() ? 0 : 1;
	}
	 