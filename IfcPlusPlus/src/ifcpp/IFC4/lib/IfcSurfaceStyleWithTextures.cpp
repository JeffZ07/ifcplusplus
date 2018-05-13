/* Code generated by IfcQuery EXPRESS generator, www.ifcquery.com */
#include <sstream>
#include <limits>

#include "ifcpp/model/AttributeObject.h"
#include "ifcpp/model/BuildingException.h"
#include "ifcpp/model/BuildingGuid.h"
#include "ifcpp/reader/ReaderUtil.h"
#include "ifcpp/writer/WriterUtil.h"
#include "ifcpp/IFC4/include/IfcSurfaceStyleWithTextures.h"
#include "ifcpp/IFC4/include/IfcSurfaceTexture.h"

// ENTITY IfcSurfaceStyleWithTextures 
IfcSurfaceStyleWithTextures::IfcSurfaceStyleWithTextures() {}
IfcSurfaceStyleWithTextures::IfcSurfaceStyleWithTextures( int id ) { m_entity_id = id; }
IfcSurfaceStyleWithTextures::~IfcSurfaceStyleWithTextures() {}
shared_ptr<BuildingObject> IfcSurfaceStyleWithTextures::getDeepCopy( BuildingCopyOptions& options )
{
	shared_ptr<IfcSurfaceStyleWithTextures> copy_self( new IfcSurfaceStyleWithTextures() );
	for( size_t ii=0; ii<m_Textures.size(); ++ii )
	{
		auto item_ii = m_Textures[ii];
		if( item_ii )
		{
			copy_self->m_Textures.push_back( dynamic_pointer_cast<IfcSurfaceTexture>(item_ii->getDeepCopy(options) ) );
		}
	}
	return copy_self;
}
void IfcSurfaceStyleWithTextures::getStepLine( std::stringstream& stream ) const
{
	stream << "#" << m_entity_id << "= IFCSURFACESTYLEWITHTEXTURES" << "(";
	writeEntityList( stream, m_Textures );
	stream << ");";
}
void IfcSurfaceStyleWithTextures::getStepParameter( std::stringstream& stream, bool ) const { stream << "#" << m_entity_id; }
const std::wstring IfcSurfaceStyleWithTextures::toString() const { return L"IfcSurfaceStyleWithTextures"; }
void IfcSurfaceStyleWithTextures::readStepArguments( const std::vector<std::wstring>& args, const std::map<int,shared_ptr<BuildingEntity> >& map )
{
	const size_t num_args = args.size();
	if( num_args != 1 ){ std::stringstream err; err << "Wrong parameter count for entity IfcSurfaceStyleWithTextures, expecting 1, having " << num_args << ". Entity ID: " << m_entity_id << std::endl; throw BuildingException( err.str().c_str() ); }
	readEntityReferenceList( args[0], m_Textures, map );
}
void IfcSurfaceStyleWithTextures::getAttributes( std::vector<std::pair<std::string, shared_ptr<BuildingObject> > >& vec_attributes )
{
	IfcPresentationItem::getAttributes( vec_attributes );
	if( m_Textures.size() > 0 )
	{
		shared_ptr<AttributeObjectVector> Textures_vec_object( new AttributeObjectVector() );
		std::copy( m_Textures.begin(), m_Textures.end(), std::back_inserter( Textures_vec_object->m_vec ) );
		vec_attributes.push_back( std::make_pair( "Textures", Textures_vec_object ) );
	}
}
void IfcSurfaceStyleWithTextures::getAttributesInverse( std::vector<std::pair<std::string, shared_ptr<BuildingObject> > >& vec_attributes_inverse )
{
	IfcPresentationItem::getAttributesInverse( vec_attributes_inverse );
}
void IfcSurfaceStyleWithTextures::setInverseCounterparts( shared_ptr<BuildingEntity> ptr_self_entity )
{
	IfcPresentationItem::setInverseCounterparts( ptr_self_entity );
	shared_ptr<IfcSurfaceStyleWithTextures> ptr_self = dynamic_pointer_cast<IfcSurfaceStyleWithTextures>( ptr_self_entity );
	if( !ptr_self ) { throw BuildingException( "IfcSurfaceStyleWithTextures::setInverseCounterparts: type mismatch" ); }
	for( size_t i=0; i<m_Textures.size(); ++i )
	{
		if( m_Textures[i] )
		{
			m_Textures[i]->m_UsedInStyles_inverse.push_back( ptr_self );
		}
	}
}
void IfcSurfaceStyleWithTextures::unlinkFromInverseCounterparts()
{
	IfcPresentationItem::unlinkFromInverseCounterparts();
	for( size_t i=0; i<m_Textures.size(); ++i )
	{
		if( m_Textures[i] )
		{
			std::vector<weak_ptr<IfcSurfaceStyleWithTextures> >& UsedInStyles_inverse = m_Textures[i]->m_UsedInStyles_inverse;
			for( auto it_UsedInStyles_inverse = UsedInStyles_inverse.begin(); it_UsedInStyles_inverse != UsedInStyles_inverse.end(); )
			{
				weak_ptr<IfcSurfaceStyleWithTextures> self_candidate_weak = *it_UsedInStyles_inverse;
				if( self_candidate_weak.expired() )
				{
					++it_UsedInStyles_inverse;
					continue;
				}
				shared_ptr<IfcSurfaceStyleWithTextures> self_candidate( *it_UsedInStyles_inverse );
				if( self_candidate.get() == this )
				{
					it_UsedInStyles_inverse= UsedInStyles_inverse.erase( it_UsedInStyles_inverse );
				}
				else
				{
					++it_UsedInStyles_inverse;
				}
			}
		}
	}
}
