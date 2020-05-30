/* Code generated by IfcQuery EXPRESS generator, www.ifcquery.com */
#include <sstream>
#include <limits>

#include "ifcpp/model/AttributeObject.h"
#include "ifcpp/model/BuildingException.h"
#include "ifcpp/model/BuildingGuid.h"
#include "ifcpp/reader/ReaderUtil.h"
#include "ifcpp/writer/WriterUtil.h"
#include "ifcpp/IFC4/include/IfcAnnotation.h"
#include "ifcpp/IFC4/include/IfcElement.h"
#include "ifcpp/IFC4/include/IfcGloballyUniqueId.h"
#include "ifcpp/IFC4/include/IfcLabel.h"
#include "ifcpp/IFC4/include/IfcOwnerHistory.h"
#include "ifcpp/IFC4/include/IfcPositioningElement.h"
#include "ifcpp/IFC4/include/IfcProduct.h"
#include "ifcpp/IFC4/include/IfcRelContainedInSpatialStructure.h"
#include "ifcpp/IFC4/include/IfcSpatialElement.h"
#include "ifcpp/IFC4/include/IfcText.h"

// ENTITY IfcRelContainedInSpatialStructure 
IfcRelContainedInSpatialStructure::IfcRelContainedInSpatialStructure( int id ) { m_entity_id = id; }
shared_ptr<BuildingObject> IfcRelContainedInSpatialStructure::getDeepCopy( BuildingCopyOptions& options )
{
	shared_ptr<IfcRelContainedInSpatialStructure> copy_self( new IfcRelContainedInSpatialStructure() );
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
	for( size_t ii=0; ii<m_RelatedElements.size(); ++ii )
	{
		auto item_ii = m_RelatedElements[ii];
		if( item_ii )
		{
			copy_self->m_RelatedElements.emplace_back( dynamic_pointer_cast<IfcProduct>(item_ii->getDeepCopy(options) ) );
		}
	}
	if( m_RelatingStructure ) { copy_self->m_RelatingStructure = dynamic_pointer_cast<IfcSpatialElement>( m_RelatingStructure->getDeepCopy(options) ); }
	return copy_self;
}
void IfcRelContainedInSpatialStructure::getStepLine( std::stringstream& stream ) const
{
	stream << "#" << m_entity_id << "= IFCRELCONTAINEDINSPATIALSTRUCTURE" << "(";
	if( m_GlobalId ) { m_GlobalId->getStepParameter( stream ); } else { stream << "$"; }
	stream << ",";
	if( m_OwnerHistory ) { stream << "#" << m_OwnerHistory->m_entity_id; } else { stream << "$"; }
	stream << ",";
	if( m_Name ) { m_Name->getStepParameter( stream ); } else { stream << "$"; }
	stream << ",";
	if( m_Description ) { m_Description->getStepParameter( stream ); } else { stream << "$"; }
	stream << ",";
	writeEntityList( stream, m_RelatedElements );
	stream << ",";
	if( m_RelatingStructure ) { stream << "#" << m_RelatingStructure->m_entity_id; } else { stream << "$"; }
	stream << ");";
}
void IfcRelContainedInSpatialStructure::StepLine2XML(tinyxml2::XMLElement* element_entity)
{
	std::string str;
	element_entity->SetAttribute("Type", "IFCRELCONTAINEDINSPATIALSTRUCTURE");
	element_entity->SetAttribute("Entity_ID", m_entity_id);
	if (m_GlobalId) {
		str = encodeStepString(m_GlobalId->toString());
		const char* ch = str.c_str();
		element_entity->SetAttribute("IFCGLOBALLYUNIQUEID", ch);
	}
	else { element_entity->SetAttribute("IFCGLOBALLYUNIQUEID", ""); }

	if (m_OwnerHistory) {
		element_entity->SetAttribute("OwnerHistory", m_OwnerHistory->m_entity_id);
	}
	else { element_entity->SetAttribute("OwnerHistory", ""); }

	if (m_Name) {
		str = encodeStepString(m_Name->toString());
		const char* namechr = str.c_str();
		element_entity->SetAttribute("IFCLABEL", namechr);
	}
	else { element_entity->SetAttribute("IFCLABEL", ""); }

	if (m_Description) {
		str = encodeStepString(m_Description->toString());
		const char* Deschr = str.c_str();
		element_entity->SetAttribute("Description", Deschr);
	}
	else { element_entity->SetAttribute("Description", ""); }
	if (m_RelatingStructure) { element_entity->SetAttribute("RelatingObject", m_RelatingStructure->m_entity_id); }
	else { element_entity->SetAttribute("RelatingObject", ""); }
	writeEntityList2XML(element_entity, m_RelatedElements);

}

void IfcRelContainedInSpatialStructure::getStepParameter( std::stringstream& stream, bool /*is_select_type*/ ) const { stream << "#" << m_entity_id; }
const std::wstring IfcRelContainedInSpatialStructure::toString() const { return L"IfcRelContainedInSpatialStructure"; }
void IfcRelContainedInSpatialStructure::readStepArguments( const std::vector<std::wstring>& args, const std::map<int,shared_ptr<BuildingEntity> >& map )
{
	const size_t num_args = args.size();
	if( num_args != 6 ){ std::stringstream err; err << "Wrong parameter count for entity IfcRelContainedInSpatialStructure, expecting 6, having " << num_args << ". Entity ID: " << m_entity_id << std::endl; throw BuildingException( err.str().c_str() ); }
	m_GlobalId = IfcGloballyUniqueId::createObjectFromSTEP( args[0], map );
	readEntityReference( args[1], m_OwnerHistory, map );
	m_Name = IfcLabel::createObjectFromSTEP( args[2], map );
	m_Description = IfcText::createObjectFromSTEP( args[3], map );
	readEntityReferenceList( args[4], m_RelatedElements, map );
	readEntityReference( args[5], m_RelatingStructure, map );
}
void IfcRelContainedInSpatialStructure::getAttributes( std::vector<std::pair<std::string, shared_ptr<BuildingObject> > >& vec_attributes ) const
{
	IfcRelConnects::getAttributes( vec_attributes );
	if( !m_RelatedElements.empty() )
	{
		shared_ptr<AttributeObjectVector> RelatedElements_vec_object( new AttributeObjectVector() );
		std::copy( m_RelatedElements.begin(), m_RelatedElements.end(), std::back_inserter( RelatedElements_vec_object->m_vec ) );
		vec_attributes.emplace_back( std::make_pair( "RelatedElements", RelatedElements_vec_object ) );
	}
	vec_attributes.emplace_back( std::make_pair( "RelatingStructure", m_RelatingStructure ) );
}
void IfcRelContainedInSpatialStructure::getAttributesInverse( std::vector<std::pair<std::string, shared_ptr<BuildingObject> > >& vec_attributes_inverse ) const
{
	IfcRelConnects::getAttributesInverse( vec_attributes_inverse );
}
void IfcRelContainedInSpatialStructure::setInverseCounterparts( shared_ptr<BuildingEntity> ptr_self_entity )
{
	IfcRelConnects::setInverseCounterparts( ptr_self_entity );
	shared_ptr<IfcRelContainedInSpatialStructure> ptr_self = dynamic_pointer_cast<IfcRelContainedInSpatialStructure>( ptr_self_entity );
	if( !ptr_self ) { throw BuildingException( "IfcRelContainedInSpatialStructure::setInverseCounterparts: type mismatch" ); }
	for( size_t i=0; i<m_RelatedElements.size(); ++i )
	{
		shared_ptr<IfcAnnotation>  RelatedElements_IfcAnnotation = dynamic_pointer_cast<IfcAnnotation>( m_RelatedElements[i] );
		if( RelatedElements_IfcAnnotation )
		{
			RelatedElements_IfcAnnotation->m_ContainedInStructure_inverse.emplace_back( ptr_self );
		}
		shared_ptr<IfcElement>  RelatedElements_IfcElement = dynamic_pointer_cast<IfcElement>( m_RelatedElements[i] );
		if( RelatedElements_IfcElement )
		{
			RelatedElements_IfcElement->m_ContainedInStructure_inverse.emplace_back( ptr_self );
		}
		shared_ptr<IfcPositioningElement>  RelatedElements_IfcPositioningElement = dynamic_pointer_cast<IfcPositioningElement>( m_RelatedElements[i] );
		if( RelatedElements_IfcPositioningElement )
		{
			RelatedElements_IfcPositioningElement->m_ContainedInStructure_inverse.emplace_back( ptr_self );
		}
	}
	if( m_RelatingStructure )
	{
		m_RelatingStructure->m_ContainsElements_inverse.emplace_back( ptr_self );
	}
}
void IfcRelContainedInSpatialStructure::unlinkFromInverseCounterparts()
{
	IfcRelConnects::unlinkFromInverseCounterparts();
	for( size_t i=0; i<m_RelatedElements.size(); ++i )
	{
		shared_ptr<IfcAnnotation>  RelatedElements_IfcAnnotation = dynamic_pointer_cast<IfcAnnotation>( m_RelatedElements[i] );
		if( RelatedElements_IfcAnnotation )
		{
			std::vector<weak_ptr<IfcRelContainedInSpatialStructure> >& ContainedInStructure_inverse = RelatedElements_IfcAnnotation->m_ContainedInStructure_inverse;
			for( auto it_ContainedInStructure_inverse = ContainedInStructure_inverse.begin(); it_ContainedInStructure_inverse != ContainedInStructure_inverse.end(); )
			{
				weak_ptr<IfcRelContainedInSpatialStructure> self_candidate_weak = *it_ContainedInStructure_inverse;
				if( self_candidate_weak.expired() )
				{
					++it_ContainedInStructure_inverse;
					continue;
				}
				shared_ptr<IfcRelContainedInSpatialStructure> self_candidate( *it_ContainedInStructure_inverse );
				if( self_candidate.get() == this )
				{
					it_ContainedInStructure_inverse= ContainedInStructure_inverse.erase( it_ContainedInStructure_inverse );
				}
				else
				{
					++it_ContainedInStructure_inverse;
				}
			}
		}
		shared_ptr<IfcElement>  RelatedElements_IfcElement = dynamic_pointer_cast<IfcElement>( m_RelatedElements[i] );
		if( RelatedElements_IfcElement )
		{
			std::vector<weak_ptr<IfcRelContainedInSpatialStructure> >& ContainedInStructure_inverse = RelatedElements_IfcElement->m_ContainedInStructure_inverse;
			for( auto it_ContainedInStructure_inverse = ContainedInStructure_inverse.begin(); it_ContainedInStructure_inverse != ContainedInStructure_inverse.end(); )
			{
				weak_ptr<IfcRelContainedInSpatialStructure> self_candidate_weak = *it_ContainedInStructure_inverse;
				if( self_candidate_weak.expired() )
				{
					++it_ContainedInStructure_inverse;
					continue;
				}
				shared_ptr<IfcRelContainedInSpatialStructure> self_candidate( *it_ContainedInStructure_inverse );
				if( self_candidate.get() == this )
				{
					it_ContainedInStructure_inverse= ContainedInStructure_inverse.erase( it_ContainedInStructure_inverse );
				}
				else
				{
					++it_ContainedInStructure_inverse;
				}
			}
		}
		shared_ptr<IfcPositioningElement>  RelatedElements_IfcPositioningElement = dynamic_pointer_cast<IfcPositioningElement>( m_RelatedElements[i] );
		if( RelatedElements_IfcPositioningElement )
		{
			std::vector<weak_ptr<IfcRelContainedInSpatialStructure> >& ContainedInStructure_inverse = RelatedElements_IfcPositioningElement->m_ContainedInStructure_inverse;
			for( auto it_ContainedInStructure_inverse = ContainedInStructure_inverse.begin(); it_ContainedInStructure_inverse != ContainedInStructure_inverse.end(); )
			{
				weak_ptr<IfcRelContainedInSpatialStructure> self_candidate_weak = *it_ContainedInStructure_inverse;
				if( self_candidate_weak.expired() )
				{
					++it_ContainedInStructure_inverse;
					continue;
				}
				shared_ptr<IfcRelContainedInSpatialStructure> self_candidate( *it_ContainedInStructure_inverse );
				if( self_candidate.get() == this )
				{
					it_ContainedInStructure_inverse= ContainedInStructure_inverse.erase( it_ContainedInStructure_inverse );
				}
				else
				{
					++it_ContainedInStructure_inverse;
				}
			}
		}
	}
	if( m_RelatingStructure )
	{
		std::vector<weak_ptr<IfcRelContainedInSpatialStructure> >& ContainsElements_inverse = m_RelatingStructure->m_ContainsElements_inverse;
		for( auto it_ContainsElements_inverse = ContainsElements_inverse.begin(); it_ContainsElements_inverse != ContainsElements_inverse.end(); )
		{
			weak_ptr<IfcRelContainedInSpatialStructure> self_candidate_weak = *it_ContainsElements_inverse;
			if( self_candidate_weak.expired() )
			{
				++it_ContainsElements_inverse;
				continue;
			}
			shared_ptr<IfcRelContainedInSpatialStructure> self_candidate( *it_ContainsElements_inverse );
			if( self_candidate.get() == this )
			{
				it_ContainsElements_inverse= ContainsElements_inverse.erase( it_ContainsElements_inverse );
			}
			else
			{
				++it_ContainsElements_inverse;
			}
		}
	}
}
