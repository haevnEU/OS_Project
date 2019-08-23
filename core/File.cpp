//
// Created by Leon Heindl on 22.08.2019.
//

#include "File.h"

FileData::FileData(unsigned long int size) {
    this->data = new char[size];
}

File::File(FileData* data, std::string *name, std::string *ext, char uid, char gid,
                                     char permission, long access, long created, long changed) : data(data),name(name),ext(ext),
                                                                                                 uid(uid), gid(gid),
                                                                                                 permission(permission),
                                                                                                 access(access),
                                                                                                 created(created),
                                                                                                 changed(changed) {

}

std::string *File::getName() const {
    return name;
}

void File::setName(std::string *name) {
    File::name = name;
}

std::string *File::getExt() const {
    return ext;
}

void File::setExt(std::string *ext) {
    File::ext = ext;
}

char File::getUid() const {
    return uid;
}

void File::setUid(char uid) {
    File::uid = uid;
}

char File::getGid() const {
    return gid;
}

void File::setGid(char gid) {
    File::gid = gid;
}

char File::getPermission() const {
    return permission;
}

void File::setPermission(char permission) {
    File::permission = permission;
}

long File::getAccess() const {
    return access;
}

void File::setAccess(long access) {
    File::access = access;
}

long File::getCreated() const {
    return created;
}

void File::setCreated(long created) {
    File::created = created;
}

long File::getChanged() const {
    return changed;
}

void File::setChanged(long changed) {
    File::changed = changed;
}

FileData *File::getData() const {
    return data;
}

void File::setData(FileData *data) {
    File::data = data;
}

const std::string* File::getPath() const {
    return path;
}

void File::setPath(std::string * path) {
    File::path = path;
}

