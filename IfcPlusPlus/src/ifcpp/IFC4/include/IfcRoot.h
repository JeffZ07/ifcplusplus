/* Code generated by IfcQuery EXPRESS generator, www.ifcquery.com */
#pragma once
#include <vector>
#include <map>
#include <sstream>
#include <string>
#include "ifcpp/model/GlobalDefines.h"
#include "ifcpp/model/BasicTypes.h"
#include "ifcpp/model/BuildingObject.h"
class IFCQUERY_EXPORT IfcGloballyUniqueId;
class IFCQUERY_EXPORT IfcOwnerHistory;
class IFCQUERY_EXPORT IfcLabel;
class IFCQUERY_EXPORT IfcText;
//ENTITY
class IFCQUERY_EXPORT IfcRoot : public BuildingEntity
{ 
public:
	IfcRoot() = default;
	IfcRoot( int id );
	~IfcRoot() = default;
	virtual shared_ptr<BuildingObject> getDeepCopy( BuildingCopyOptions& options );
	virtual void getStepLine( std::stringstream& stream ) const;
	virtual void StepLine2XML(tinyxml2::XMLElement*);
	virtual void getStepParameter( std::stringstream& stream, bool is_select_type = false ) const;
	virtual void readStepArguments( const std::vector<std::wstring>& args, const std::map<int,shared_ptr<BuildingEntity> >& map );
	virtual void setInverseCounterparts( shared_ptr<BuildingEntity> ptr_self );
	virtual size_t getNumAttributes() { return 4; }
	virtual void getAttributes( std::vector<std::pair<std::string, shared_ptr<BuildingObject> > >& vec_attributes ) const;
	virtual void getAttributesInverse( std::vector<std::pair<std::string, shared_ptr<BuildingObject> > >& vec_attributes ) const;
	virtual void unlinkFromInverseCounterparts();
	virtual const char* className() const { return "IfcRoot"; }
	virtual const std::wstring toString() const;


	// IfcRoot -----------------------------------------------------------
	// attributes:
	shared_ptr<IfcGloballyUniqueId>	m_GlobalId;
	shared_ptr<IfcOwnerHistory>		m_OwnerHistory;				//optional
	shared_ptr<IfcLabel>			m_Name;						//optional
	shared_ptr<IfcText>				m_Description;				//optional
};

