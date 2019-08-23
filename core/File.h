//
// Created by Leon Heindl on 22.08.2019.
//

#ifndef OS_PROJECT_FILE_H
#define OS_PROJECT_FILE_H

#include <string>

/**
 * Struct for holding Data
 * @author Leon Heindl
 */
struct FileData{
    /**
     * Constructor for data struct
     * @param size the amount of data bytes
     */
    FileData(unsigned long int size);
    ///data char array
    char* data;
    /// the lengst of the data array
    unsigned long int length;
};

/**
 * File Class holds all relevant information about a file and its content
 * @author Leon Heindl
 */
class File {
private:
    FileData* data;
    std::string* path;
    std::string* name;
    std::string* ext;
    char uid;
    char gid;
    char permission;
    long access;
    long created;
    long changed;
public:
    File(FileData* data, std::string *name, std::string *ext, char uid, char gid, char permission, long access,
                      long created, long changed);

    FileData *getData() const;

    void setData(FileData *data);

    const std::string * getPath() const;

    void setPath(std::string * path);

    std::string *getName() const;

    void setName(std::string *name);

    std::string *getExt() const;

    void setExt(std::string *ext);

    char getUid() const;

    void setUid(char uid);

    char getGid() const;

    void setGid(char gid);

    char getPermission() const;

    void setPermission(char permission);

    long getAccess() const;

    void setAccess(long access);

    long getCreated() const;

    void setCreated(long created);

    long getChanged() const;

    void setChanged(long changed);
};


#endif //OS_PROJECT_FILE_H
