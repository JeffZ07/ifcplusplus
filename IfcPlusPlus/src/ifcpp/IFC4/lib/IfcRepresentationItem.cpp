/* Code generated by IfcQuery EXPRESS generator, www.ifcquery.com */
#include <sstream>
#include <limits>

#include "ifcpp/model/AttributeObject.h"
#include "ifcpp/model/BuildingException.h"
#include "ifcpp/model/BuildingGuid.h"
#include "ifcpp/reader/ReaderUtil.h"
#include "ifcpp/writer/WriterUtil.h"
#include "ifcpp/IFC4/include/IfcPresentationLayerAssignment.h"
#include "ifcpp/IFC4/include/IfcRepresentationItem.h"
#include "ifcpp/IFC4/include/IfcStyledItem.h"

// ENTITY IfcRepresentationItem 
IfcRepresentationItem::IfcRepresentationItem( int id ) { m_entity_id = id; }
shared_ptr<BuildingObject> IfcRepresentationItem::getDeepCopy( BuildingCopyOptions& options )
{
	shared_ptr<IfcRepresentationItem> copy_self( new IfcRepresentationItem() );
	return copy_self;
}
void IfcRepresentationItem::getStepLine( std::stringstream& stream ) const
{
	stream << "#" << m_entity_id << "= IFCREPRESENTATIONITEM" << "(";
	stream << ");";
}
void IfcRepresentationItem::StepLine2XML(tinyxml2::XMLElement* element_entity) const
{
	element_entity->SetAttribute("Type", "IFCREPRESENTATIONITEM");
	element_entity->SetAttribute("Entity_ID", m_entity_id);
}
void IfcRepresentationItem::getStepParameter( std::stringstream& stream, bool /*is_select_type*/ ) const { stream << "#" << m_entity_id; }
const std::wstring IfcRepresentationItem::toString() const { return L"IfcRepresentationItem"; }
void IfcRepresentationItem::readStepArguments( const std::vector<std::wstring>& args, const std::map<int,shared_ptr<BuildingEntity> >& map )
{
}
void IfcRepresentationItem::getAttributes( std::vector<std::pair<std::string, shared_ptr<BuildingObject> > >& vec_attributes ) const
{
}
void IfcRepresentationItem::getAttributesInverse( std::vector<std::pair<std::string, shared_ptr<BuildingObject> > >& vec_attributes_inverse ) const
{
	if( !m_LayerAssignment_inverse.empty() )
	{
		shared_ptr<AttributeObjectVector> LayerAssignment_inverse_vec_obj( new AttributeObjectVector() );
		for( size_t i=0; i<m_LayerAssignment_inverse.size(); ++i )
		{
			if( !m_LayerAssignment_inverse[i].expired() )
			{
				LayerAssignment_inverse_vec_obj->m_vec.emplace_back( shared_ptr<IfcPresentationLayerAssignment>( m_LayerAssignment_inverse[i] ) );
			}
		}
		vec_attributes_inverse.emplace_back( std::make_pair( "LayerAssignment_inverse", LayerAssignment_inverse_vec_obj ) );
	}
	if( !m_StyledByItem_inverse.empty() )
	{
		shared_ptr<AttributeObjectVector> StyledByItem_inverse_vec_obj( new AttributeObjectVector() );
		for( size_t i=0; i<m_StyledByItem_inverse.size(); ++i )
		{
			if( !m_StyledByItem_inverse[i].expired() )
			{
				StyledByItem_inverse_vec_obj->m_vec.emplace_back( shared_ptr<IfcStyledItem>( m_StyledByItem_inverse[i] ) );
			}
		}
		vec_attributes_inverse.emplace_back( std::make_pair( "StyledByItem_inverse", StyledByItem_inverse_vec_obj ) );
	}
}
void IfcRepresentationItem::setInverseCounterparts( shared_ptr<BuildingEntity> )
{
}
void IfcRepresentationItem::unlinkFromInverseCounterparts()
{
}
