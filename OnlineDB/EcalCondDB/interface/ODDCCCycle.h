#ifndef ODDCCCYCLE_H
#define ODDCCCYCLE_H

#include <stdexcept>
#include <iostream>

#include "OnlineDB/EcalCondDB/interface/IODConfig.h"



class ODDCCCycle :  public IODConfig  {
 public:
  friend class EcalCondDBInterface;
  friend class ODEcalCycle;

  ODDCCCycle();
  ~ODDCCCycle();

  inline std::string getTable() { return "ECAL_DCC_CYCLE"; }

  inline void setId(int id){m_ID=id;}
  inline int getId()const{ return m_ID;} ;

  // Methods for user data
  inline void setDCCConfigurationID(int x){m_dcc_config_id=x;}
  inline int getDCCConfigurationID() const{return m_dcc_config_id;}

  // Operators
  inline bool operator==(const ODDCCCycle &m) const { return ( m_ID   == m.m_ID); }
  inline bool operator!=(const ODDCCCycle &m) const { return !(*this == m); }

 private:
  // User data 
  int m_ID;
  int  m_dcc_config_id;
  void writeDB() throw(std::runtime_error);
  void prepareWrite()  throw(std::runtime_error);
  void clear();
  void fetchData(ODDCCCycle * result)     throw(std::runtime_error);
  void insertConfig() throw(std::runtime_error);


  // Methods from IUniqueDBObject
  int fetchID() throw(std::runtime_error);
  void setByID(int id) throw(std::runtime_error);


};

#endif
