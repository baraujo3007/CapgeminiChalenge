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
#include "funclib.h"

using namespace CppUnit;
using namespace std;

class TestCountAnagrams : public CppUnit::TestFixture {
	    CPPUNIT_TEST_SUITE(TestCountAnagrams);
	    CPPUNIT_TEST(testToLower);
		CPPUNIT_TEST(testAreAnagrams);
		CPPUNIT_TEST(testCount);
        CPPUNIT_TEST_SUITE_END();
	public:
	    void setUp(void);
	    void tearDown(void);
	 
	protected:
	    void testToLower(void);
		void testAreAnagrams(void);
		void testCount(void);
};

void TestCountAnagrams::testToLower(void){

		CPPUNIT_ASSERT("abc" == toLower("ABC"));

}


void TestCountAnagrams::testAreAnagrams(void){
	    
		CPPUNIT_ASSERT(1 == areAnagrams("a", "a"));
        CPPUNIT_ASSERT(1 == areAnagrams("ab", "ba"));
        CPPUNIT_ASSERT(1 == areAnagrams("abc", "cba"));
        CPPUNIT_ASSERT(1 == areAnagrams("abcd", "dbca"));
        CPPUNIT_ASSERT(0 == areAnagrams("abcd", "efgh"));

}


void TestCountAnagrams::testCount(void){
	    
		CPPUNIT_ASSERT(12 == countAnagrams("arara"));
        CPPUNIT_ASSERT(0 == countAnagrams("sofa"));

}

	void TestCountAnagrams::setUp(void)
	{
	    

	}
	 
	void TestCountAnagrams::tearDown(void)
	{
	    

	}

    	CPPUNIT_TEST_SUITE_REGISTRATION( TestCountAnagrams );
	 
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
    
	 