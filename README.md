# LilDIS-local
Local REDIS-like Dictionary Database

# Usage Example

    #include  <iostream>
    #include  "LilDIS.h"
    
    using  namespace  std;
    
    int  main() {
    
	    // Create a new lilDIS instance
	    
	    LilDIS  lilDIS;
	    
	    // If database file does not exist, create it.
	    
	    if (!lilDIS.check_db_exists())
	    {
	    lilDIS.create_db();
	    }
	    
	    // For loading the database from hard-disk
	    
	    lilDIS.read_data_from_disk();
	    
	    //Let's write some data to the database
	    
	    lilDIS.write("hello","world");
	    
	    //Let's read the data from the database
	    
	    lilDIS.read("hello"); //Output is "world"
	    
	    //Let's delete the data from the database
	    
	    lilDIS.delet("hello");
	    
	    //Let's check if the data is deleted
	    
	    lilDIS.read("hello"); //Output is "NULL"
	    
	    //For saving the data permamently to the hard-disk
	    
	    lilDIS.write_data_to_disk();
    }
