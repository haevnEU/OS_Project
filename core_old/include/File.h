#ifndef _OS_PROJECT_FILE_H_
#define _OS_PROJECT_FILE_H_

#include <iostream>

#include <string>

namespace os_project {
	namespace fileSystem {
		class File {
		private:


			/// 8 bit attribute
			/// +-------+-------+-------+-------+-------+-------+-------+-------+
			/// |   7   |   6   |   5   |   4   |   3   |   2   |   1   |   0   |
			/// +-------+-------+-------+-------+-------+-------+-------+-------+
			/// | FREE  |  DEL  | MODI  |  DIR  |  SYS  |  HID  |  EXE  |   RO  |
			/// +-------+-------+-------+-------+-------+-------+-------+-------+
			unsigned char attributes_m;
			
			/// This attribute is the create oder modify time
			/// Bit  0 -  5: Seconds
			/// Bit  6 - 10: Minutes
			/// Bit 11 - 15: Hours
			unsigned short createModifyTime_m;

			/// This attribute is the create oder modify date
			/// Bit  0 -  5: Days
			/// Bit  6 - 10: Months
			/// Bit 11 - 15: Years(Starting from 1970)
			unsigned short createModifyDate_m;

			/// This attribute describes the owner of the file
			unsigned char userID_m;

			/// This attributes stores in which blocks the data is stored on the disk
			int* clusterIndize_m;

			/// This attribute is the file extension, Important it is not NULL terminated
			char extension_m[3];

			/// This attribute is the file name, Important it is not NULL terminated
			char name_m[8];

			/// This attribute is the file size
			int size_m;

			// This attribute is a file id
			int fileID_m;

			/// This attributes describes how many blocks are occupied by this file
			int usedBlocks_m;

		public:


			 File(int fileSize, const char name[], const char extension[], 
				 int attributes, int userID, int timeStamp, int dateStamp);

			~File(void);

			void deleteFile(void);

			const char* name(void);

			int size(void);

			int occupiedBlocks(void);

			int fileID(void);

			int userID(void);

			int attributes(int attributeMask);

			int lastModifyDate(void);

			int lastModifyTime(void);
			
			int clusterIndex(int index);


			std::string getAttributesAsString();

			std::string getTimeAsString();

			std::string getDateAsString();

			
			void setAttribute(int mask);

			void setAttributes(int mask);

			void clearAttribute(int mask);

			void clearAttributes(int mask);

			const char* data();

			void DBG_setTime(unsigned short);

			/**
			 * TODO write comment
			 */
			friend std::ostream& operator<< (std::ostream& out, File& block);


		};

	}
}

#endif // _OS_PROJECT_FILE_H_
