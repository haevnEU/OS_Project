#ifndef PAGES_ENUM_H
#define PAGES_ENUM_H

//! This namespace contains all ui elements for this project
namespace ui{
    //! This namespace contains all wizards for this project
    namespace wizard{
        //! This namespace contains all wizard pages for this project
        namespace pages{
        /**
         * @brief This enum contains different available pages
         * @details This enum is used to differentiate between all possible pages,
         *          It it used to create a dynamic wizard
         */
        enum pages_enum{introPage = 1, summaryPage = 2, diskPage = 4, partitionPage = 8};
        } // pages
    } // wizard
} // ui

#define KB (1024L)
#define MB (1024L * KB)
#define GB (1024L * MB)
#define TB (1024L * GB)

#endif // PAGES_ENUM_H
