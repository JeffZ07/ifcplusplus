/* Code generated by IfcQuery EXPRESS generator, www.ifcquery.com */
#include <sstream>
#include <limits>

#include "ifcpp/model/AttributeObject.h"
#include "ifcpp/model/BuildingException.h"
#include "ifcpp/model/BuildingGuid.h"
#include "ifcpp/reader/ReaderUtil.h"
#include "ifcpp/writer/WriterUtil.h"
#include "ifcpp/IFC4/include/IfcGloballyUniqueId.h"
#include "ifcpp/IFC4/include/IfcIdentifier.h"
#include "ifcpp/IFC4/include/IfcLabel.h"
#include "ifcpp/IFC4/include/IfcObjectPlacement.h"
#include "ifcpp/IFC4/include/IfcOwnerHistory.h"
#include "ifcpp/IFC4/include/IfcProductRepresentation.h"
#include "ifcpp/IFC4/include/IfcRelAggregates.h"
#include "ifcpp/IFC4/include/IfcRelAssigns.h"
#include "ifcpp/IFC4/include/IfcRelAssignsToProduct.h"
#include "ifcpp/IFC4/include/IfcRelAssociates.h"
#include "ifcpp/IFC4/include/IfcRelConnectsElements.h"
#include "ifcpp/IFC4/include/IfcRelConnectsWithRealizingElements.h"
#include "ifcpp/IFC4/include/IfcRelContainedInSpatialStructure.h"
#include "ifcpp/IFC4/include/IfcRelCoversBldgElements.h"
#include "ifcpp/IFC4/include/IfcRelDeclares.h"
#include "ifcpp/IFC4/include/IfcRelDefinesByObject.h"
#include "ifcpp/IFC4/include/IfcRelDefinesByProperties.h"
#include "ifcpp/IFC4/include/IfcRelDefinesByType.h"
#include "ifcpp/IFC4/include/IfcRelFillsElement.h"
#include "ifcpp/IFC4/include/IfcRelInterferesElements.h"
#include "ifcpp/IFC4/include/IfcRelNests.h"
#include "ifcpp/IFC4/include/IfcRelProjectsElement.h"
#include "ifcpp/IFC4/include/IfcRelReferencedInSpatialStructure.h"
#include "ifcpp/IFC4/include/IfcRelSpaceBoundary.h"
#include "ifcpp/IFC4/include/IfcRelVoidsElement.h"
#include "ifcpp/IFC4/include/IfcText.h"
#include "ifcpp/IFC4/include/IfcWall.h"
#include "ifcpp/IFC4/include/IfcWallTypeEnum.h"

// ENTITY IfcWall 
IfcWall::IfcWall( int id ) { m_entity_id = id; }
shared_ptr<BuildingObject> IfcWall::getDeepCopy( BuildingCopyOptions& options )
{
	shared_ptr<IfcWall> copy_self( new IfcWall() );
	if( m_GlobalId )
	{
		if( options.create_new_IfcGloballyUniqueId ) { copy_self->m_GlobalId = make_shared<IfcGloballyUniqueId>( createBase64Uuid_wstr().data() ); }
		else { copy_self->m_GlobalId = dynamic_pointer_cast<IfcGloballyUniqueId>( m_GlobalId->getDeepCopy(options) ); }
	}
	if( m_OwnerHistory )
	{
		if( options.shallow_copy_IfcOwnerHistory ) { copy_self->m_OwnerHistory = m_OwnerHistory; }
		else { copy_self->m_OwnerHistory = dynamic_pointer_cast<IfcOwnerHistory>( m_OwnerHistory->getDeepCopy(options) ); }
	}
	if( m_Name ) { copy_self->m_Name = dynamic_pointer_cast<IfcLabel>( m_Name->getDeepCopy(options) ); }
	if( m_Description ) { copy_self->m_Description = dynamic_pointer_cast<IfcText>( m_Description->getDeepCopy(options) ); }
	if( m_ObjectType ) { copy_self->m_ObjectType = dynamic_pointer_cast<IfcLabel>( m_ObjectType->getDeepCopy(options) ); }
	if( m_ObjectPlacement ) { copy_self->m_ObjectPlacement = dynamic_pointer_cast<IfcObjectPlacement>( m_ObjectPlacement->getDeepCopy(options) ); }
	if( m_Representation ) { copy_self->m_Representation = dynamic_pointer_cast<IfcProductRepresentation>( m_Representation->getDeepCopy(options) ); }
	if( m_Tag ) { copy_self->m_Tag = dynamic_pointer_cast<IfcIdentifier>( m_Tag->getDeepCopy(options) ); }
	if( m_PredefinedType ) { copy_self->m_PredefinedType = dynamic_pointer_cast<IfcWallTypeEnum>( m_PredefinedType->getDeepCopy(options) ); }
	return copy_self;
}
void IfcWall::getStepLine( std::stringstream& stream ) const
{
	stream << "#" << m_entity_id << "= IFCWALL" << "(";
	if( m_GlobalId ) { m_GlobalId->getStepParameter( stream ); } else { stream << "$"; }
	stream << ",";
	if( m_OwnerHistory ) { stream << "#" << m_OwnerHistory->m_entity_id; } else { stream << "$"; }
	stream << ",";
	if( m_Name ) { m_Name->getStepParameter( stream ); } else { stream << "$"; }
	stream << ",";
	if( m_Description ) { m_Description->getStepParameter( stream ); } else { stream << "$"; }
	stream << ",";
	if( m_ObjectType ) { m_ObjectType->getStepParameter( stream ); } else { stream << "$"; }
	stream << ",";
	if( m_ObjectPlacement ) { stream << "#" << m_ObjectPlacement->m_entity_id; } else { stream << "$"; }
	stream << ",";
	if( m_Representation ) { stream << "#" << m_Representation->m_entity_id; } else { stream << "$"; }
	stream << ",";
	if( m_Tag ) { m_Tag->getStepParameter( stream ); } else { stream << "$"; }
	stream << ",";
	if( m_PredefinedType ) { m_PredefinedType->getStepParameter( stream ); } else { stream << "$"; }
	stream << ");";
}
void IfcWall::StepLine2XML(tinyxml2::XMLElement* element_entity, boost::property_tree::ptree& pt, std::map<std::string, boost::property_tree::ptree> &Dic, std::string stream) const
{
	std::string str;
	pt.put("Source", stream);

	element_entity->SetAttribute("Type", "IFCOBJECT");
	pt.put("Type", "IFCOBJECT");

	element_entity->SetAttribute("Entity_ID", m_entity_id);
	std::ostringstream s;
	s << m_entity_id;
	pt.put("Entity_ID", s.str());

	pt.put("Parent", "");

	if (m_GlobalId) {
		str = encodeStepString(m_GlobalId->toString());
		const char* ch = str.c_str();
		element_entity->SetAttribute("IFCGLOBALLYUNIQUEID", ch);
		pt.put("IFCGLOBALLYUNIQUEID", str);
	}
	else { element_entity->SetAttribute("IFCGLOBALLYUNIQUEID", ""); }


	if (m_OwnerHistory) {
		element_entity->SetAttribute("OwnerHistory", m_OwnerHistory->m_entity_id);
		std::ostringstream s2;
		s2 << m_OwnerHistory->m_entity_id;
		pt.put("OwnerHistory", s2.str());
	}
	else { element_entity->SetAttribute("OwnerHistory", ""); }

	if (m_Name) {
		str = encodeStepString(m_Name->toString());
		const char* namechr = str.c_str();
		element_entity->SetAttribute("IFCLABEL", namechr);
		pt.put("IFCLABEL", str);
	}
	else { element_entity->SetAttribute("IFCLABEL", ""); }

	if (m_Description) {
		str = encodeStepString(m_Description->toString());
		const char* Deschr = str.c_str();
		element_entity->SetAttribute("Description", Deschr);
		pt.put("Description", str);
	}
	else { element_entity->SetAttribute("Description", ""); }

	if (m_ObjectType) {
		str = encodeStepString(m_ObjectType->toString());
		const char* Onjchr = str.c_str();
		element_entity->SetAttribute("ObjectType", Onjchr);
		pt.put("ObjectType", str);
	}
	else { element_entity->SetAttribute("ObjectType", ""); }

	Dic[s.str()] = pt;
}

void IfcWall::getStepParameter( std::stringstream& stream, bool /*is_select_type*/ ) const { stream << "#" << m_entity_id; }
const std::wstring IfcWall::toString() const { return L"IfcWall"; }
void IfcWall::readStepArguments( const std::vector<std::wstring>& args, const std::map<int,shared_ptr<BuildingEntity> >& map )
{
	const size_t num_args = args.size();
	if( num_args != 9 ){ std::stringstream err; err << "Wrong parameter count for entity IfcWall, expecting 9, having " << num_args << ". Entity ID: " << m_entity_id << std::endl; throw BuildingException( err.str().c_str() ); }
	m_GlobalId = IfcGloballyUniqueId::createObjectFromSTEP( args[0], map );
	readEntityReference( args[1], m_OwnerHistory, map );
	m_Name = IfcLabel::createObjectFromSTEP( args[2], map );
	m_Description = IfcText::createObjectFromSTEP( args[3], map );
	m_ObjectType = IfcLabel::createObjectFromSTEP( args[4], map );
	readEntityReference( args[5], m_ObjectPlacement, map );
	readEntityReference( args[6], m_Representation, map );
	m_Tag = IfcIdentifier::createObjectFromSTEP( args[7], map );
	m_PredefinedType = IfcWallTypeEnum::createObjectFromSTEP( args[8], map );
}
void IfcWall::getAttributes( std::vector<std::pair<std::string, shared_ptr<BuildingObject> > >& vec_attributes ) const
{
	IfcBuildingElement::getAttributes( vec_attributes );
	vec_attributes.emplace_back( std::make_pair( "PredefinedType", m_PredefinedType ) );
}
void IfcWall::getAttributesInverse( std::vector<std::pair<std::string, shared_ptr<BuildingObject> > >& vec_attributes_inverse ) const
{
	IfcBuildingElement::getAttributesInverse( vec_attributes_inverse );
}
void IfcWall::setInverseCounterparts( shared_ptr<BuildingEntity> ptr_self_entity )
{
	IfcBuildingElement::setInverseCounterparts( ptr_self_entity );
}
void IfcWall::unlinkFromInverseCounterparts()
{
	IfcBuildingElement::unlinkFromInverseCounterparts();
}
